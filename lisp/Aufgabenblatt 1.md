#Arbeitsblatt 1

## Syntax von jQuery

### $("selector").aktion("Eigenschaften_der_Aktion");

>Selector: Elemente, die bearbeitet, manipuliert oder verändert werden sollen (HTML-Elemente).
* Mehrere Selectoren durch Kommata, mehrere Aktionen durch "."-Schachtelung, sowie mehrere Eigenschaften der Aktionen durch Kommata möglich:
```jquery  
  $("selector1, selector2, ... selectorN").aktion.aktion2.aktion3("Eigenschaft1",..."EigenschaftN");
``` 
 >Filter: Elemente, welche die Arbeit mit Selektoren um einiges verfeinern.
