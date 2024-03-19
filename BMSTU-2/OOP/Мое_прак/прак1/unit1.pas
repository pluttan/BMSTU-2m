unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, TAGraph, LResources, Forms, Controls, Graphics,
  Dialogs, mysql80conn, StdCtrls, Menus, DBGrids, Interfaces, sqldb, db,
  TASeries, TASources;

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

{ TForm1 }


procedure TForm1.FormCreate(Sender: TObject);
var stadium, team1, team2, score : string;
begin
      Label7.caption := '';
      SQLQuery1.SQL.Text := 'SELECT * FROM gameFB';
      SQLQuery1.Open;
      ListBox1.Items.Clear;
      ListBox1.Items.Add('------------------------------------------');
      count := 0;
      while not SQLQuery1.Eof do
      begin
        stadium := 'Стадион: ' + SQLQuery1.FieldByName('stadium').AsString;
        team1   := 'Команды: ' + SQLQuery1.FieldByName('team1').AsString;
        team2   := ' против ' + SQLQuery1.FieldByName('team2').AsString;
        score  := 'Счет: ' +SQLQuery1.FieldByName('score1').AsString+':'+
                               SQLQuery1.FieldByName('score2').AsString;
        count := count + 1;
        ListBox1.Items.Add('ИГРА ' + SQLQuery1.FieldByName('id').AsString);
        ListBox1.Items.Add(stadium);
        ListBox1.Items.Add(team1 + team2);
        ListBox1.Items.Add(score);
        ListBox1.Items.Add('------------------------------------------');
        showMessage(SQLQuery1.FieldByName('id').AsString);
        SQLQuery1.Next;

      end;
      SQLTransaction1.Commit;
      SQLQuery1.Close;

      SQLQuery1.SQL.Text := 'SELECT DISTINCT team1 as team FROM gameFB UNION SELECT DISTINCT team2 as team FROM gameFB;';
      SQLQuery1.Open;
      ListBox2.Items.Clear;
      count := 0;
      while not SQLQuery1.Eof do
      begin
        ListBox2.Items.Add(SQLQuery1.FieldByName('team').AsString);
        SQLQuery1.Next;
      end;
      SQLTransaction1.Commit;
      SQLQuery1.Close;

      Chart1.BottomAxis.Title.Caption := 'Стадион';
      //Chart1.BottomAxis.LabelsFont.Size := 8; // Размер шрифта для засечек
      //Chart1.BottomAxis.LabelsFont.Color := clBlue; // Цвет шрифта для засечек
      //Chart1.BottomAxis.LabelsFont.Style := [fsBold]; // Стиль шрифта для засечек
      //Chart1.BottomAxis.LabelsAngle := 45; // Угол поворота засечек в градусах

      SQLQuery1.SQL.Text := 'SELECT COUNT(*) AS count_duplicates, stadium FROM gameFB GROUP BY stadium';
      SQLQuery1.Open;
      BarSeries := TBarSeries.Create(Chart1);
      Chart1.AddSeries(BarSeries);
      BarSeries.Title := 'Количество повторений';
      label9.caption := '';
      count := 0;
      while not SQLQuery1.Eof do
      begin
        count := count + 1;
        BarSeries.Add(StrToInt(SQLQuery1.FieldByName('count_duplicates').AsString));
        label9.caption := label9.caption + inttostr(count) + ' ' + SQLQuery1.FieldByName('stadium').AsString + #10#13;
        SQLQuery1.Next;
      end;
      SQLTransaction1.Commit;
      SQLQuery1.Close;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin

  if (edit1.caption <> '') and
     (edit6.caption <> '') and
     (edit3.caption <> '') and
     (edit4.caption <> '') and
     (edit5.caption <> '') then
     begin
       SQLQuery1.SQL.Text := 'INSERT INTO gameFB (stadium, team1, team2, score1, score2, id) VALUES (';
       SQLQuery1.SQL.Text := SQLQuery1.SQL.Text + edit1.caption + ',' + edit6.caption + ','
                                                + edit3.caption + ',' + edit4.caption + ','
                                                + edit5.caption + ',' + inttostr(count + 1)+')';
       SQLQuery1.ExecSQL;
       SQLQuery1.SQL.Text := 'SET @num := 0';
       SQLQuery1.ExecSQL;
       SQLQuery1.SQL.Text := 'UPDATE gameFB SET id = @num := @num + 1';
       SQLQuery1.ExecSQL;
       SQLTransaction1.Commit;
       FormCreate(Sender);
     end
  else
      showmessage('Не все колонки заполнены');
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
    SQLQuery1.SQL.Text := 'SELECT team, COUNT(*) as wins FROM (SELECT team1 as team, score1, score2 FROM gameFB UNION ALL SELECT team2 as team, score2, score1 FROM gameFB) as games WHERE score1 > score2 GROUP BY team HAVING wins >= :wins;';
    SQLQuery1.Params.ParamByName('wins').AsInteger := strtoint(edit2.text);
    SQLQuery1.Open;
    Label7.caption := 'Команды: ';
    count := 0;
    while not SQLQuery1.Eof do
    begin
      Label7.caption := Label7.caption + #10#13 + SQLQuery1.FieldByName('team').AsString;
      SQLQuery1.Next;
    end;
    SQLTransaction1.Commit;
    SQLQuery1.Close;
end;

procedure TForm1.Button7Click(Sender: TObject);
var stadium, team1, team2, score : string;
begin
    SQLQuery1.SQL.Text := 'SELECT * FROM gameFB where score1 = score2';
    SQLQuery1.Open;
    Label7.caption := '';
    Label7.caption := Label7.caption + #10#13 + '------------------------------------------';
    count := 0;
    while not SQLQuery1.Eof do
    begin
      stadium := 'Стадион: ' + SQLQuery1.FieldByName('stadium').AsString;
      team1   := 'Команды: ' + SQLQuery1.FieldByName('team1').AsString;
      team2   := ' против ' + SQLQuery1.FieldByName('team2').AsString;
      score  := 'Счет: ' +SQLQuery1.FieldByName('score1').AsString+':'+
                          SQLQuery1.FieldByName('score2').AsString;
      count := count + 1;
      Label7.caption := Label7.caption + #10#13 + 'ИГРА ' + SQLQuery1.FieldByName('id').AsString;
      Label7.caption := Label7.caption + #10#13 + stadium;
      Label7.caption := Label7.caption + #10#13 + team1 + team2;
      Label7.caption := Label7.caption + #10#13 + score;
      Label7.caption := Label7.caption + #10#13 + '------------------------------------------';
      SQLQuery1.Next;
    end;
    SQLTransaction1.Commit;
    SQLQuery1.Close;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
    SQLQuery1.SQL.Text := 'DELETE FROM gameFB WHERE id = :id';
    SQLQuery1.Params.ParamByName('id').AsInteger := (ListBox1.ItemIndex + 1) div 5 + 1;
    SQLQuery1.ExecSQL;
    SQLQuery1.SQL.Text := 'SET @num := 0';
    SQLQuery1.ExecSQL;
    SQLQuery1.SQL.Text := 'UPDATE gameFB SET id = @num := @num + 1';
    SQLQuery1.ExecSQL;
    SQLTransaction1.Commit;
    FormCreate(Sender);
end;

procedure TForm1.Button2Click(Sender: TObject);
var i:integer;
begin
  SQLQuery1.SQL.Text := edit7.text;
  SQLQuery1.Open;
  Label7.caption := '';
  if not SQLQuery1.IsEmpty then
  begin
    SQLQuery1.First;
    while not SQLQuery1.Eof do
    begin
      for i := 0 to SQLQuery1.FieldCount - 1 do
      begin
        Label7.Caption := Label7.Caption + SQLQuery1.Fields[i].AsString + #9;
      end;
      Label7.Caption := Label7.Caption + #10#13;
      SQLQuery1.Next;
    end;
  end;
  SQLQuery1.Close;
  SQLTransaction1.Commit;
end;

procedure TForm1.Button4Click(Sender: TObject);
var stadium, team1, team2, score : string;
begin
    SQLQuery1.SQL.Text := 'SELECT * FROM gameFB where team1 = :team or team2 = :team2';
    SQLQuery1.Params.ParamByName('team').AsString := ListBox2.Items[ListBox2.ItemIndex];
    SQLQuery1.Params.ParamByName('team2').AsString := ListBox2.Items[ListBox2.ItemIndex];
    SQLQuery1.Open;
    Label7.caption := '';
    Label7.caption := Label7.caption + #10#13 + '------------------------------------------';
    count := 0;
    while not SQLQuery1.Eof do
    begin
      stadium := 'Стадион: ' + SQLQuery1.FieldByName('stadium').AsString;
      team1   := 'Команды: ' + SQLQuery1.FieldByName('team1').AsString;
      team2   := ' против ' + SQLQuery1.FieldByName('team2').AsString;
      score  := 'Счет: ' +SQLQuery1.FieldByName('score1').AsString+':'+
                          SQLQuery1.FieldByName('score2').AsString;
      count := count + 1;
      Label7.caption := Label7.caption + #10#13 + 'ИГРА ' + SQLQuery1.FieldByName('id').AsString;
      Label7.caption := Label7.caption + #10#13 + stadium;
      Label7.caption := Label7.caption + #10#13 + team1 + team2;
      Label7.caption := Label7.caption + #10#13 + score;
      Label7.caption := Label7.caption + #10#13 + '------------------------------------------';
      SQLQuery1.Next;
    end;
    SQLTransaction1.Commit;
    SQLQuery1.Close;
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


