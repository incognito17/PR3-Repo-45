# Arbeitsblatt 1

## Aufgabe 1:

a) rotiere:
```lisp  
  (defun rotiere (l)  
    (append (cdr l)
      (list (car l))
    )
  )
``` 
b) neues-vorletztes:
```lisp  
  (defun neues-vorletztes (a b)  
    (append (reverse (cdr (reverse b)))
            (list a) (last b)
    )
  )
```





## Baum-Darstellung
Man kann einen binären Baum als Liste folgendermaßen darstellen:

Den Wurzelknoten kann man als das erste Element der Liste wählen, den linken Unterbaum beispielsweise als zweiten und den rechten Unterbaum als dritten und letzten Element.

Für alle anderen Teilbäume, kann man dieses Schema beibehalten, sodass sich immer für jeweils einen (Teil)Baum eine Liste der Länge 3 ergibt. (Falls der Baum nur einen rechten bzw. nur einen linken Teilbaum hat, kann man für den fehlenden Unterbaum eine leere Liste als Element übergeben).

Beispiel: 

[![](https://github.com/pr3-lecture/repo-45/blob/master/lisp/drv01.png)]()

Mit obiger Beschreibung, lässt sich der oben dargestellte Baum wie folgt als Liste darstellen:

> (7 (3 (2 () ()) (5 () ())) (11 (10 () ()) (12 () (40 () () ))) )

Mit 7 als Wurzelknoten (erstes Element), 3 + geschachtelter linker Unterbaum (zweites Element), 11 + geschachtelter rechter Unterbaum (letztes Element).
Die fehlenden Knoten eines Blattes, werden als leere Listen --> () <-- dargestellt.


## Baum-Traversierung

* Postorder
```lisp  
  (defun postorder (l)
              (cond
                 ((or (not (listp l)) (null l)) nil)
                 ((and (null (cadr l)) (null (caddr l))) l)
                 (t (append (postorder (cadr l)) (postorder (caddr l)) (list (car l))))
               )
  )

``` 
 * Preorder
 
 ```lisp  
  (defun preorder (l)
              (cond
                ((or (not (listp l)) (null l)) nil)
                ((and (null (cadr l)) (null (caddr l))) l)
                (t (append (list (car l)) (preorder (cadr l)) (preorder (caddr l))))
              )
  )

```
 * Inorder
 
  ```lisp  
   (defun inorder (l)
               (cond
                	((or (not (listp l)) (null l)) nil)
                  (( and (null (cadr l)) (null (caddr l))) l)
                  (t (append (inorder (cadr l)) (list (car l)) (inorder (caddr l))))
                 )
   )

```
 
 
 
 
