
Type TSet = Object
  Private 
    FList: array Of Variant;
  Public 
    constructor Create;
    Procedure Add(AValue: Variant);
    Procedure Delete(AValue: Variant);
    Function Contain(AValue: Variant): Boolean;
    Procedure Print;
End;

constructor TSet.Create;
Begin
  SetLength(FList, 0);
End;

Procedure TSet.Add(AValue: Variant);

Var 
  I: Integer;
Begin
  If Not Contain(AValue) Then
    Begin
      I := Length(FList);
      SetLength(FList, I + 1);
      FList[I] := AValue;
    End;
End;

Procedure TSet.Delete(AValue: Variant);

Var 
  I, J: Integer;
Begin
  I := 0;
  While I < Length(FList) Do
    Begin
      If FList[I] = AValue Then
        Begin
          For J := I To Length(FList) - 2 Do
            FList[J] := FList[J + 1];
          SetLength(FList, Length(FList) - 1);
        End
      Else
        Inc(I);
    End;
End;

Function TSet.Contain(AValue: Variant): Boolean;

Var 
  I: Integer;
  Result: Boolean;
Begin
  Result := False;
  For I := 0 To Length(FList) - 1 Do
    Begin
      If FList[I] = AValue Then
        Begin
          Result := True;
          Break;
        End;
    End;
  contain := result;
End;

Procedure TSet.Print;

Var 
  I: Integer;
Begin
  Write('Elements of the set: ');
  For I := 0 To Length(FList) - 1 Do
    Write(FList[I], ' ');
  writeln;
End;

Type 
  TCardinalitySet = Object(TSet)
    Public 
      Function Cardinality: Integer;
  End;

Function TCardinalitySet.Cardinality: Integer;
Begin
  Cardinality := Length(FList);
End;

Var PSetChar, PSetInt: TSet;
  PCardinalitySet: TCardinalitySet;
Begin
  writeln;
  PSetChar.create;
  PSetChar.add('b');
  PSetChar.add('a');
  PSetChar.print;
  PSetChar.delete('b');
  PSetChar.print;
  writeln('is b in set: ', PSetChar.contain('b'));
  writeln('is a in set: ', PSetChar.contain('a'));

  writeln;
  PSetInt.create;
  PSetInt.add(1);
  PSetInt.add(2);
  PSetInt.print;
  PSetInt.delete(1);
  PSetInt.print;
  writeln('is 1 in set: ', PSetInt.contain(1));
  writeln('is 2 in set: ', PSetInt.contain(2));

  writeln;
  PCardinalitySet.create;
  PCardinalitySet.add(56);
  PCardinalitySet.add(65);
  PCardinalitySet.print;
  writeln('Cardinality of set: ', PCardinalitySet.Cardinality);
End.
