// generated by Fast Light User Interface Designer (fluid) version 1.0305

#include "fltk.h"

Fl_Double_Window* fltkWin::make_window() {
  { win01 = new Fl_Double_Window(465, 210, "Kenzanin SimAvr Gui");
    win01->user_data((void*)(this));
    win01->when(FL_WHEN_NEVER);
    { fnameOut = new Fl_Output(5, 5, 295, 25, "asdasdasdasd");
      fnameOut->box(FL_BORDER_BOX);
    } // Fl_Output* fnameOut
    { btn01 = new Fl_Button(315, 5, 135, 25, "Load Firmware");
      btn01->callback((Fl_Callback*)btn01Cb);
    } // Fl_Button* btn01
    { Fl_Box* o = new Fl_Box(5, 36, 80, 25, "Firmware :");
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(5, 67, 50, 25, "MCU :");
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(5, 99, 50, 25, "Freq :");
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Box* o
    { outFirmware = new Fl_Output(90, 36, 210, 25);
      outFirmware->box(FL_BORDER_BOX);
    } // Fl_Output* outFirmware
    { outMcu = new Fl_Output(90, 67, 210, 25);
      outMcu->box(FL_BORDER_BOX);
    } // Fl_Output* outMcu
    { outFreq = new Fl_Output(90, 99, 210, 25);
      outFreq->box(FL_BORDER_BOX);
    } // Fl_Output* outFreq
    { btnRun = new Fl_Button(315, 33, 135, 93, "Stop");
      btnRun->labelsize(24);
      btnRun->callback((Fl_Callback*)btnRunCb);
    } // Fl_Button* btnRun
    { Fl_Box* o = new Fl_Box(5, 140, 60, 25, "PORTB");
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Box* o
    { pbOut = new Fl_Value_Output(64, 140, 56, 25);
    } // Fl_Value_Output* pbOut
    win01->end();
  } // Fl_Double_Window* win01
  return win01;
}
