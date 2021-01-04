#include "Fl/Fl_File_Chooser.h"
#include "fltk.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <libgen.h>
#include <pthread.h>
#include <string>

#include "button.h"
#include <simavr/avr_ioport.h>
#include <simavr/sim_avr.h>
#include <simavr/sim_elf.h>
#include <simavr/sim_gdb.h>
#include <simavr/sim_io.h>
#include <simavr/sim_vcd_file.h>

fltkWin w;
elf_firmware_t f;
avr_t *avr;
uint8_t pin_state = 0;
uint8_t avrRunStatus = 0;
pthread_t t;

void *task01(void *);

void portbChangeHook(struct avr_irq_t *irq, uint32_t value, void *param) {
  Fl::lock();
  pin_state = (pin_state & ~(1 << irq->irq)) | (value << irq->irq);
  w.pbOut->value(pin_state);
  Fl::unlock();
  Fl::awake();
}

void btn01Cb(Fl_Button *, void *) {
  Fl::lock();
  printf("button cb\n");
  char *file = fl_file_chooser("Select Firmware", "Elf (*.elf)\tHex (*.hex)",
                               "firmware.elf", 0);
  w.fnameOut->value(file);
  elf_read_firmware(file, &f);
  avr = avr_make_mcu_by_name(f.mmcu);
  w.outFreq->value(std::to_string(f.frequency).c_str());
  w.outFirmware->value(basename(file));
  w.outMcu->value(f.mmcu);

  avr_init(avr);
  avr_load_firmware(avr, &f);

  for (int i = 0; i < 8; i++) {
    avr_irq_register_notify(avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'), i),
                            portbChangeHook, NULL);
  }
  int rc = pthread_create(&t, NULL, task01, NULL);
  if (rc) {
    printf("gagal bikin thread\n");
  }
  Fl::unlock();
  Fl::awake();
}

void *task01(void *) {
  while (1) {
    if (avrRunStatus == 1) {
      avr_run(avr);
    }
  }
}

void btnRunCb(Fl_Button *, void *) {
  Fl::lock();
  if (avrRunStatus == 0) {
    w.btnRun->label("Run");
    avrRunStatus = 1;
  } else {
    w.btnRun->label("Stop");
    avrRunStatus = 0;
  }
  Fl::unlock();
  Fl::awake();
}
void win01KeyCb(Fl_Double_Window *, void *) { printf("entered key\n"); }

int main() {
  Fl::lock();

  w.make_window()->show();
  return Fl::run();
}
