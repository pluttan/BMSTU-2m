
Unit Unit1;

{$mode objfpc}{$H+}

Interface

Uses
Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
ComCtrls, ColorBox, Buttons;

Type segment = Object
  Image1: TImage;
  lastalp: real;
  inv: shortint;
  placepointsX: array [0..8] Of integer;
  placepointsY: array [0..8] Of integer;
  XCenter, YCenter, Length, Step: integer;
  constructor init(Image: TImage);
  Procedure draw(xc, yc, d, alp:real);
End;

Type octtangle = Object(segment)
  Procedure draw(xc, yc, d, alp:real);
End;

Type rectangle = Object(segment)
  Procedure draw(xc, yc, d, alp:real);
End;

Var
  seg: segment;
  reg: rectangle;
  oct: octtangle;
  maxStep, limLength, minBar, maxTimer: integer;

Type TForm1 = Class(TForm)
  Button1: TButton;
  Button2: TButton;
  Button3: TButton;
  Button4: TButton;
  Button5: TButton;
  Button6: TButton;
  Button7: TButton;
  CheckBox1: TCheckBox;
  CheckBox2: TCheckBox;
  CheckBox3: TCheckBox;
  CheckBox4: TCheckBox;
  ColorBox1: TColorBox;
  ColorBox2: TColorBox;
  ColorBox3: TColorBox;
  Image1: TImage;
  Image2: TImage;
  Image3: TImage;
  Label1: TLabel;
  Label10: TLabel;
  Label11: TLabel;
  Label12: TLabel;
  Label13: TLabel;
  Label14: TLabel;
  Label15: TLabel;
  Label16: TLabel;
  Label17: TLabel;
  Label18: TLabel;
  Label19: TLabel;
  Label2: TLabel;
  Label20: TLabel;
  Label21: TLabel;
  Label22: TLabel;
  Label23: TLabel;
  Label24: TLabel;
  Label25: TLabel;
  Label26: TLabel;
  Label27: TLabel;
  Label28: TLabel;
  Label29: TLabel;
  Label3: TLabel;
  Label30: TLabel;
  Label31: TLabel;
  Label32: TLabel;
  Label33: TLabel;
  Label34: TLabel;
  Label35: TLabel;
  Label36: TLabel;
  Label37: TLabel;
  Label38: TLabel;
  Label39: TLabel;
  Label4: TLabel;
  Label40: TLabel;
  Label41: TLabel;
  Label42: TLabel;
  Label43: TLabel;
  Label44: TLabel;
  Label45: TLabel;
  Label46: TLabel;
  Label47: TLabel;
  Label48: TLabel;
  Label49: TLabel;
  Label5: TLabel;
  Label50: TLabel;
  Label51: TLabel;
  Label52: TLabel;
  Label53: TLabel;
  Label54: TLabel;
  Label55: TLabel;
  Label56: TLabel;
  Label57: TLabel;
  Label58: TLabel;
  Label59: TLabel;
  Label6: TLabel;
  Label60: TLabel;
  Label61: TLabel;
  Label62: TLabel;
  Label63: TLabel;
  Label64: TLabel;
  Label65: TLabel;
  Label66: TLabel;
  Label67: TLabel;
  Label68: TLabel;
  Label69: TLabel;
  Label7: TLabel;
  Label70: TLabel;
  Label71: TLabel;
  Label72: TLabel;
  Label73: TLabel;
  Label74: TLabel;
  Label75: TLabel;
  Label76: TLabel;
  Label77: TLabel;
  Label78: TLabel;
  Label79: TLabel;
  Label8: TLabel;
  Label80: TLabel;
  Label81: TLabel;
  Label82: TLabel;
  Label83: TLabel;
  Label84: TLabel;
  Label85: TLabel;
  Label86: TLabel;
  Label87: TLabel;
  Label88: TLabel;
  Label89: TLabel;
  Label9: TLabel;
  Label90: TLabel;
  Label91: TLabel;
  Label92: TLabel;
  Label93: TLabel;
  Label94: TLabel;
  Timer1: TTimer;
  Timer2: TTimer;
  Timer3: TTimer;
  TrackBar1: TTrackBar;
  TrackBar16: TTrackBar;
  TrackBar17: TTrackBar;
  TrackBar18: TTrackBar;
  TrackBar19: TTrackBar;
  TrackBar2: TTrackBar;
  TrackBar20: TTrackBar;
  TrackBar3: TTrackBar;
  TrackBar4: TTrackBar;
  TrackBar5: TTrackBar;
  TrackBar6: TTrackBar;
  TrackBar7: TTrackBar;
  TrackBar8: TTrackBar;
  TrackBar9: TTrackBar;
  TrackBar10: TTrackBar;
  TrackBar11: TTrackBar;
  TrackBar12: TTrackBar;
  TrackBar13: TTrackBar;
  TrackBar14: TTrackBar;
  TrackBar15: TTrackBar;
  Procedure Button1Click(Sender: TObject);
  Procedure Button2Click(Sender: TObject);
  Procedure Button3Click(Sender: TObject);
  Procedure Button4Click(Sender: TObject);
  Procedure Button5Click(Sender: TObject);
  Procedure Button6Click(Sender: TObject);
  Procedure Button7Click(Sender: TObject);
  Procedure CheckBox1Change(Sender: TObject);
  Procedure CheckBox2Change(Sender: TObject);
  Procedure CheckBox3Change(Sender: TObject);
  Procedure CheckBox4Change(Sender: TObject);
  Procedure FormCreate(Sender: TObject);
  Procedure Timer1Timer(Sender: TObject);
  Procedure Timer2Timer(Sender: TObject);
  Procedure Timer3Timer(Sender: TObject);
  Procedure TrackBar1Change(Sender: TObject);
  Procedure TrackBar2Change(Sender: TObject);
  Procedure TrackBar3Change(Sender: TObject);
  Procedure TrackBar4Change(Sender: TObject);
  Procedure TrackBar5Change(Sender: TObject);
  Procedure TrackBar6Change(Sender: TObject);
  Procedure TrackBar7Change(Sender: TObject);
  Procedure TrackBar8Change(Sender: TObject);
  Procedure TrackBar9Change(Sender: TObject);
  Procedure TrackBar10Change(Sender: TObject);
  Procedure TrackBar11Change(Sender: TObject);
  Procedure TrackBar12Change(Sender: TObject);
  Procedure TrackBar13Change(Sender: TObject);
  Procedure TrackBar14Change(Sender: TObject);
  Procedure TrackBar15Change(Sender: TObject);
  Procedure TrackBar16Change(Sender: TObject);
  Procedure TrackBar17Change(Sender: TObject);
  Procedure TrackBar18Change(Sender: TObject);
  Procedure TrackBar19Change(Sender: TObject);
  Procedure TrackBar20Change(Sender: TObject);
End;

Var
  Form1: TForm1;

Implementation

{$R *.lfm}

Procedure clear(image:TImage; CheckBox:TCheckBox; ColorBox:TColorBox);
Begin
  If CheckBox.Checked Then Image.Canvas.Brush.Color := $444444
  Else Image.Canvas.Brush.Color := $FFFFFF;

  Image.Canvas.FillRect(Rect(0, 0, Image.Width, Image.Height));
  Image.Canvas.Pen.Width := 5;
  Image.Canvas.Pen.Color := Colorbox.Selected;
  Image.canvas.MoveTo(0, 0) ;
  Image.canvas.LineTo(Image.Width, 0);
  Image.canvas.LineTo(Image.Width, Image.Height);
  Image.canvas.LineTo(0, Image.Height);
  Image.canvas.LineTo(0, 0);
  Image.Canvas.Pen.Width := 10;
End;

Procedure addCaptionReal(lbl:TLabel; int:real);

Var s: string[10];
Begin
  s := FloatToStr(int);
  lbl.Caption := s
End;

Procedure addCaption(lbl:TLabel; int:integer);

Var s: string[4];
Begin
  str(int,s);
  lbl.Caption := s
End;

Procedure addCaptionXY(lbl:TLabel; intX, intY:integer);

Var s1,s2: string[4];
Begin
  str(intX,s1);
  str(intY,s2);
  lbl.Caption := '('+s1+', '+s2+')'
End;

Procedure reloadBar(TrackBar:TTrackBar);
Begin
  TrackBar.position := TrackBar.position+1;
  TrackBar.max := TrackBar.max+1;
  TrackBar.position := TrackBar.position-1;
  TrackBar.max := TrackBar.max-1;
End;

constructor segment.init(Image: TImage);
Begin
  Image1 := Image;
  lastalp := 0;
  inv := 1;
End;

Procedure segment.draw(xc, yc, d, alp:real);
Begin
  self.lastalp := alp;
  alp := -alp*inv;
  self.placepointsX[0] := round(xc+d*cos(alp));
  self.placepointsX[1] := round(xc-d*cos(alp));
  self.placepointsY[0] := round(yc-d*sin(alp));
  self.placepointsY[1] := round(yc+d*sin(alp));
  Image1.canvas.MoveTo(self.placepointsX[0], self.placepointsY[0]);
  Image1.canvas.LineTo(self.placepointsX[1], self.placepointsY[1]);
End;

Procedure rectangle.draw(xc, yc, d, alp:real);

Var x1, x2, y1, y2, x, y: real;
  i: integer;
Begin
  self.lastalp := alp;
  alp := alp*inv;
  x1 := xc-d/2;
  x2 := xc+d/2;
  y1 := yc-d/2;
  y2 := yc+d/2;
  For i:=0 To 4 Do
    Begin
      Case i Of
        0:
           Begin
             x := x1;
             y := y1;
           End;
        1:
           Begin
             x := x2;
             y := y1;
           End;
        2:
           Begin
             x := x2;
             y := y2;
           End;
        3:
           Begin
             x := x1;
             y := y2;
           End;
        4:
           Begin
             x := x1;
             y := y1;
           End;
      End;
      self.placepointsX[i] := round(xc + (x - xc) * cos(alp) - (y - yc) * sin(
                              alp));
      self.placepointsY[i] := round(yc + (x - xc) * sin(alp) + (y - yc) * cos(
                              alp));
      If i=0 Then Image1.canvas.MoveTo(self.placepointsX[i],  self.placepointsY[
                                       i])
      Else Image1.canvas.LineTo(self.placepointsX[i], self.placepointsY[i]);
    End;
End;

Procedure octtangle.draw(xc, yc, d, alp:real);

Var x1, x2, x3, x4, y1, y2, y3, y4, x, y: real;
  i: integer;
Begin
  self.lastalp := alp;
  alp := alp*inv;
  x1 := xc-d*sin(pi/4);
  x2 := xc-d;
  x3 := xc+d*sin(pi/4);
  x4 := xc+d;
  y1 := yc+d*sin(pi/4);
  y2 := yc-d*sin(pi/4);
  y3 := yc-d;
  y4 := yc+d;
  For i:=0 To 8 Do
    Begin
      Case i Of
        0:
           Begin
             x := x1;
             y := y1;
           End;
        1:
           Begin
             x := x2;
             y := yc;
           End;
        2:
           Begin
             x := x1;
             y := y2;
           End;
        3:
           Begin
             x := xc;
             y := y3;
           End;
        4:
           Begin
             x := x3;
             y := y2;
           End;
        5:
           Begin
             x := x4;
             y := yc;
           End;
        6:
           Begin
             x := x3;
             y := y1;
           End;
        7:
           Begin
             x := xc;
             y := y4;
           End;
        8:
           Begin
             x := x1;
             y := y1;
           End;
      End;
      self.placepointsX[i] := round(xc + (x - xc) * cos(alp) - (y - yc) * sin(
                              alp));
      self.placepointsY[i] := round(yc + (x - xc) * sin(alp) + (y - yc) * cos(
                              alp));
      If i=0 Then Image1.canvas.MoveTo(self.placepointsX[i],  self.placepointsY[
                                       i])
      Else Image1.canvas.LineTo(self.placepointsX[i], self.placepointsY[i]);
    End;
End;

Procedure TForm1.FormCreate(Sender: TObject);
Begin
  maxStep := 200;
  maxTimer := 100;
  limLength := 100;
  minBar := 0;

  CheckBox4.Checked := true;

  seg.init(Image1);
  reg.init(Image2);
  oct.init(Image3);

  TrackBar16.min := 100;
  TrackBar17.min := 100;
  TrackBar18.min := 0;
  TrackBar19.min := -100;
  TrackBar20.min := 100;

  TrackBar16.max := 500;
  TrackBar17.max := 500;
  TrackBar18.max := 250;
  TrackBar19.max := 100;
  TrackBar20.max := 700;

  TrackBar16.position := 200;
  TrackBar17.position := 100;
  TrackBar18.position := 100;
  TrackBar19.position := 0;
  TrackBar20.position := 700;

  TrackBar1.min := minBar;
  TrackBar2.min := minBar;
  TrackBar3.min := minBar;
  TrackBar4.min := minBar;
  TrackBar5.min := minBar;
  TrackBar6.min := minBar;
  TrackBar7.min := minBar;
  TrackBar8.min := minBar;
  TrackBar9.min := minBar;
  TrackBar10.min := minBar;
  TrackBar11.min := minBar;
  TrackBar12.min := minBar;
  TrackBar13.min := minBar+1;
  TrackBar14.min := minBar+1;
  TrackBar15.min := minBar+1;


  TrackBar1.max := Image1.Width;
  TrackBar2.max := Image2.Width;
  TrackBar3.max := Image3.Width;
  TrackBar4.max := Image1.Height;
  TrackBar5.max := Image2.Height;
  TrackBar6.max := Image3.Height;
  TrackBar7.max := round((Image1.Height+Image1.Width)/2-limLength);
  TrackBar8.max := round((Image2.Height+Image2.Width)/2-limLength);
  TrackBar9.max := round((Image3.Height+Image3.Width)/2-limLength);
  TrackBar10.max := maxStep;
  TrackBar11.max := maxStep;
  TrackBar12.max := maxStep;
  TrackBar13.max := maxTimer;
  TrackBar14.max := maxTimer;
  TrackBar15.max := maxTimer;


  TrackBar1.position := round(TrackBar1.max/2);
  TrackBar2.position := round(TrackBar2.max/2);
  TrackBar3.position := round(TrackBar3.max/2);
  TrackBar4.position := round(TrackBar4.max/2);
  TrackBar5.position := round(TrackBar5.max/2);
  TrackBar6.position := round(TrackBar6.max/2);
  TrackBar7.position := round(TrackBar7.max/2);
  TrackBar8.position := round(TrackBar8.max/2);
  TrackBar9.position := round(TrackBar9.max/3);
  TrackBar10.position := round(TrackBar10.max/8);
  TrackBar11.position := round(TrackBar11.max/8);
  TrackBar12.position := round(TrackBar12.max/8);
  TrackBar13.position := round(TrackBar13.max/2);
  TrackBar14.position := round(TrackBar14.max/2);
  TrackBar15.position := round(TrackBar15.max/2);

End;

Procedure TForm1.CheckBox1Change(Sender: TObject);

Var tmp: integer;
Begin
  seg.Step := -seg.Step;
  tmp := TrackBar10.max;
  TrackBar10.max := -TrackBar10.min;
  TrackBar10.min := -tmp;
  If CheckBox1.Checked Then TrackBar10.position := -round(maxStep/8)
  Else TrackBar10.position := round(maxStep/8);
  reloadBar(TrackBar10);
End;

Procedure TForm1.CheckBox2Change(Sender: TObject);

Var tmp: integer;
Begin
  reg.Step := -reg.Step;
  tmp := TrackBar11.max;
  TrackBar11.max := -TrackBar11.min;
  TrackBar11.min := -tmp;
  If CheckBox2.Checked Then TrackBar11.position := -round(maxStep/8)
  Else TrackBar11.position := round(maxStep/8);
  reloadBar(TrackBar11);
End;

Procedure TForm1.CheckBox3Change(Sender: TObject);

Var tmp: integer;
Begin
  oct.Step := -oct.Step;
  tmp := TrackBar12.max;
  TrackBar12.max := -TrackBar12.min;
  TrackBar12.min := -tmp;
  If CheckBox3.Checked Then TrackBar12.position := -round(maxStep/8)
  Else TrackBar12.position := round(maxStep/8);
  reloadBar(TrackBar12);
End;

Procedure TForm1.CheckBox4Change(Sender: TObject);
Begin
  If CheckBox4.Checked Then
    Begin
      Colorbox1.Selected := clWhite;
      Colorbox2.Selected := clWhite;
      Colorbox3.Selected := clWhite;
      Form1.color := $444444;
      Form1.font.color := $FFFFFF;
      label1.font.color := $FFFFFF;
      label4.font.color := $FFFFFF;
      label5.font.color := $FFFFFF;
      label40.font.color := $FFFFFF;
      label41.font.color := $FFFFFF;
      label42.font.color := $FFFFFF;
      label94.font.color := $FFFFFF;
      reloadBar(TrackBar1);
      reloadBar(TrackBar2);
      reloadBar(TrackBar3);
      reloadBar(TrackBar4);
      reloadBar(TrackBar5);
      reloadBar(TrackBar6);
      reloadBar(TrackBar7);
      reloadBar(TrackBar8);
      reloadBar(TrackBar9);
      reloadBar(TrackBar10);
      reloadBar(TrackBar11);
      reloadBar(TrackBar12);
      reloadBar(TrackBar13);
      reloadBar(TrackBar14);
      reloadBar(TrackBar15);
      reloadBar(TrackBar16);
      reloadBar(TrackBar17);
      reloadBar(TrackBar18);
      reloadBar(TrackBar19);
      reloadBar(TrackBar20);
      ColorBox1.Color := $444444;
      ColorBox2.Color := $444444;
      ColorBox3.Color := $444444;
    End
  Else
    Begin
      Colorbox1.Selected := clBlack;
      Colorbox2.Selected := clBlack;
      Colorbox3.Selected := clBlack;
      Form1.color := clDefault;
      Form1.font.color := $000000;
      label1.font.color := $000000;
      label4.font.color := $000000;
      label5.font.color := $000000;
      label40.font.color := $000000;
      label41.font.color := $000000;
      label42.font.color := $000000;
      label94.font.color := $000000;
      ColorBox1.Color := $FFFFFF;
      ColorBox2.Color := $FFFFFF;
      ColorBox3.Color := $FFFFFF;
      reloadBar(TrackBar1);
      reloadBar(TrackBar2);
      reloadBar(TrackBar3);
      reloadBar(TrackBar4);
      reloadBar(TrackBar5);
      reloadBar(TrackBar6);
      reloadBar(TrackBar7);
      reloadBar(TrackBar8);
      reloadBar(TrackBar9);
      reloadBar(TrackBar10);
      reloadBar(TrackBar11);
      reloadBar(TrackBar12);
      reloadBar(TrackBar13);
      reloadBar(TrackBar14);
      reloadBar(TrackBar15);
      reloadBar(TrackBar16);
      reloadBar(TrackBar17);
      reloadBar(TrackBar18);
      reloadBar(TrackBar19);
      reloadBar(TrackBar20);
    End;
End;


Procedure TForm1.Button1Click(Sender: TObject);
Begin
  TrackBar10.position := 0;
End;

Procedure TForm1.Button2Click(Sender: TObject);
Begin
  CheckBox1.Checked := false;
  TrackBar1.position := round(TrackBar1.max/2);
  TrackBar4.position := round(TrackBar4.max/2);
  TrackBar7.position := round(TrackBar7.max/2);
  //TrackBar10.position := round(TrackBar10.max/8);
  TrackBar13.position := round(TrackBar13.max/2);
  seg.lastalp := 0;
End;

Procedure TForm1.Button3Click(Sender: TObject);
Begin
  TrackBar11.position := 0;
End;

Procedure TForm1.Button4Click(Sender: TObject);
Begin
  CheckBox2.Checked := false;
  TrackBar2.position := round(TrackBar1.max/2);
  TrackBar5.position := round(TrackBar4.max/2);
  TrackBar8.position := round(TrackBar7.max/2);
  //TrackBar11.position := round(TrackBar10.max/8);
  TrackBar14.position := round(TrackBar13.max/2);
  reg.lastalp := 0;
End;

Procedure TForm1.Button5Click(Sender: TObject);
Begin
  TrackBar12.position := 0;
End;

Procedure TForm1.Button6Click(Sender: TObject);
Begin
  CheckBox3.Checked := false;
  TrackBar3.position := round(TrackBar1.max/2);
  TrackBar6.position := round(TrackBar4.max/2);
  TrackBar9.position := round(TrackBar7.max/2);
  //TrackBar12.position := round(TrackBar10.max/8);
  TrackBar15.position := round(TrackBar13.max/2);
  oct.lastalp := 0;
End;

Procedure TForm1.Button7Click(Sender: TObject);
Begin
  TrackBar16.position := 200;
  TrackBar17.position := 100;
  TrackBar18.position := 100;
  TrackBar19.position := 0;
  TrackBar20.position := 700;
  CheckBox4.Checked := true;
End;

Procedure TForm1.Timer1Timer(Sender: TObject);
Begin
  clear(Image1, CheckBox4, Colorbox1);
  seg.draw(seg.XCenter,seg.YCenter,round(seg.Length/2),seg.lastalp+seg.Step/1000
  );
  addCaptionReal(Label35, TrackBar10.position/Timer1.Interval);
  addCaptionReal(Label44, (round(seg.lastalp*100) mod 314)/100);
  addCaptionXY(Label53, seg.placepointsX[0], seg.placepointsY[0]);
  addCaptionXY(Label55, seg.placepointsX[1], seg.placepointsY[1]);
End;

Procedure TForm1.Timer2Timer(Sender: TObject);
Begin
  clear(Image2, CheckBox4, Colorbox2);
  reg.draw(reg.XCenter,reg.YCenter,reg.Length,reg.lastalp+reg.Step/1000);
  addCaptionReal(Label37, TrackBar11.position/Timer2.Interval);
  addCaptionReal(Label46, (round(reg.lastalp*100) mod 314)/100);
  addCaptionXY(Label57, reg.placepointsX[0], reg.placepointsY[0]);
  addCaptionXY(Label59, reg.placepointsX[1], reg.placepointsY[1]);
  addCaptionXY(Label61, reg.placepointsX[2], reg.placepointsY[2]);
  addCaptionXY(Label63, reg.placepointsX[3], reg.placepointsY[3]);
End;

Procedure TForm1.Timer3Timer(Sender: TObject);
Begin
  clear(Image3, CheckBox4, Colorbox3);
  oct.draw(oct.XCenter,oct.YCenter,oct.Length,oct.lastalp+oct.Step/1000);
  addCaptionReal(Label39, TrackBar12.position/Timer3.Interval);
  addCaptionReal(Label48, (round(oct.lastalp*100) mod 314)/100);
  addCaptionXY(Label65, oct.placepointsX[0], oct.placepointsY[0]);
  addCaptionXY(Label67, oct.placepointsX[1], oct.placepointsY[1]);
  addCaptionXY(Label69, oct.placepointsX[2], oct.placepointsY[2]);
  addCaptionXY(Label71, oct.placepointsX[3], oct.placepointsY[3]);
  addCaptionXY(Label73, oct.placepointsX[4], oct.placepointsY[4]);
  addCaptionXY(Label75, oct.placepointsX[5], oct.placepointsY[5]);
  addCaptionXY(Label77, oct.placepointsX[6], oct.placepointsY[6]);
  addCaptionXY(Label80, oct.placepointsX[7], oct.placepointsY[7]);
End;

Procedure TForm1.TrackBar1Change(Sender: TObject);
Begin
  seg.XCenter := TrackBar1.position;
  addCaption(Label10, TrackBar1.position);
End;

Procedure TForm1.TrackBar2Change(Sender: TObject);
Begin
  reg.XCenter := TrackBar2.position;
  addCaption(Label11, TrackBar2.position);
End;

Procedure TForm1.TrackBar3Change(Sender: TObject);
Begin
  oct.XCenter := TrackBar3.position;
  addCaption(Label12, TrackBar3.position);
End;

Procedure TForm1.TrackBar4Change(Sender: TObject);
Begin
  seg.YCenter := TrackBar4.position;
  addCaption(Label13, TrackBar4.position);
End;

Procedure TForm1.TrackBar5Change(Sender: TObject);
Begin
  reg.YCenter := TrackBar5.position;
  addCaption(Label14, TrackBar5.position);
End;

Procedure TForm1.TrackBar6Change(Sender: TObject);
Begin
  oct.YCenter := TrackBar6.position;
  addCaption(Label15, TrackBar6.position);
End;

Procedure TForm1.TrackBar7Change(Sender: TObject);
Begin
  seg.Length := TrackBar7.position;
  addCaption(Label17, TrackBar7.position);
End;

Procedure TForm1.TrackBar8Change(Sender: TObject);
Begin
  reg.Length := TrackBar8.position;
  addCaption(Label20, TrackBar8.position);
End;

Procedure TForm1.TrackBar9Change(Sender: TObject);
Begin
  oct.Length := TrackBar9.position;
  addCaption(Label21, TrackBar9.position);
End;

Procedure TForm1.TrackBar10Change(Sender: TObject);
Begin
  seg.Step := TrackBar10.position;
  addCaptionReal(Label23, TrackBar10.position/1000);
End;

Procedure TForm1.TrackBar11Change(Sender: TObject);
Begin
  reg.Step := TrackBar11.position;
  addCaptionReal(Label25, TrackBar11.position/1000);
End;

Procedure TForm1.TrackBar12Change(Sender: TObject);
Begin
  oct.Step := TrackBar12.position;
  addCaptionReal(Label27, TrackBar12.position/1000);
End;

Procedure TForm1.TrackBar13Change(Sender: TObject);
Begin
  Timer1.Interval := TrackBar13.position;
  addCaption(Label29, TrackBar13.position);
End;

Procedure TForm1.TrackBar14Change(Sender: TObject);
Begin
  Timer2.Interval := TrackBar14.position;
  addCaption(Label31, TrackBar14.position);
End;

Procedure TForm1.TrackBar15Change(Sender: TObject);
Begin
  Timer3.Interval := TrackBar15.position;
  addCaption(Label33, TrackBar15.position);
End;

Procedure TForm1.TrackBar16Change(Sender: TObject);
Begin
  maxStep := TrackBar16.position;
  TrackBar10.max := maxStep;
  TrackBar11.max := maxStep;
  TrackBar12.max := maxStep;
  addCaptionReal(Label85, TrackBar16.position/1000);
End;

Procedure TForm1.TrackBar17Change(Sender: TObject);
Begin
  maxTimer := TrackBar17.position;
  TrackBar13.max := maxTimer;
  TrackBar14.max := maxTimer;
  TrackBar15.max := maxTimer;
  addCaption(Label87, TrackBar17.position);
End;

Procedure TForm1.TrackBar18Change(Sender: TObject);
Begin
  limLength := TrackBar18.position;
  TrackBar7.max := round((Image1.Height+Image1.Width)/2-limLength);
  TrackBar8.max := round((Image2.Height+Image2.Width)/2-limLength);
  TrackBar9.max := round((Image3.Height+Image3.Width)/2-limLength);
  addCaption(Label89, TrackBar18.position);
End;

Procedure TForm1.TrackBar19Change(Sender: TObject);
Begin
  minBar := TrackBar19.position;
  TrackBar1.min := minBar;
  TrackBar2.min := minBar;
  TrackBar3.min := minBar;
  TrackBar4.min := minBar;
  TrackBar5.min := minBar;
  TrackBar6.min := minBar;
  TrackBar7.min := minBar;
  TrackBar8.min := minBar;
  TrackBar9.min := minBar;
  TrackBar10.min := minBar;
  TrackBar11.min := minBar;
  TrackBar12.min := minBar;
  TrackBar13.min := minBar+1;
  TrackBar14.min := minBar+1;
  TrackBar15.min := minBar+1;
  addCaption(Label91, TrackBar19.position);
End;

Procedure TForm1.TrackBar20Change(Sender: TObject);
Begin
  Image1.Width  := TrackBar20.position;
  Image1.Height := TrackBar20.position;
  Image2.Width  := TrackBar20.position;
  Image2.Height := TrackBar20.position;
  Image3.Width  := TrackBar20.position;
  Image3.Height := TrackBar20.position;
  addCaption(Label93, TrackBar20.position);
End;


End.


