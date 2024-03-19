unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, TAGraph, LResources, Forms, Controls, Graphics,
  Dialogs, mysql80conn, StdCtrls, Menus, DBGrids, Interfaces, sqldb, db,
  TASeries, TASources, unit2, Unit3;

var count: integer;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Chart1: TChart;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    ListBox1: TListBox;
    ListBox2: TListBox;
    MySQL80Connection1: TMySQL80Connection;
    SQLQuery1: TSQLQuery;
    SQLTransaction1: TSQLTransaction;
    BarSeries: TBarSeries;
    LabelsChartSource: TListChartSource;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Label1Click(Sender: TObject);
    procedure Label2Click(Sender: TObject);
    procedure Label3Click(Sender: TObject);
    procedure Label8Click(Sender: TObject);
    procedure ListBox1Click(Sender: TObject);
    procedure MySQL80Connection1AfterConnect(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

procedure TForm1.FormCreate(Sender: TObject);
var stadium, team1, team2, score : string;
begin
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
end;

procedure TForm1.Button7Click(Sender: TObject);
var stadium, team1, team2, score : string;
begin
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
end;

procedure TForm1.Button2Click(Sender: TObject);
var i:integer;
begin
end;

procedure TForm1.Button4Click(Sender: TObject);
var stadium, team1, team2, score : string;
begin
end;


procedure TForm1.Label1Click(Sender: TObject);
begin

end;

procedure TForm1.Label2Click(Sender: TObject);
begin

end;

procedure TForm1.Label3Click(Sender: TObject);
begin

end;

procedure TForm1.Label8Click(Sender: TObject);
begin

end;

procedure TForm1.ListBox1Click(Sender: TObject);
begin
  ListBox1.ItemIndex := ListBox1.ItemIndex - ListBox1.ItemIndex mod 5 + 1;
end;


procedure TForm1.MySQL80Connection1AfterConnect(Sender: TObject);
begin

end;

end.

