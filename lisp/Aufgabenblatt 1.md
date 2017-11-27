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
  (defun neues-vorletztes (a l)  
    (append (reverse (cdr (reverse l)))
            (list a) (last l)
    )
  )
```
Wobei a das übergebene neue vorletzte Element ist und l die Liste.

c) my-length:
```lisp  
  (defun my-length (l)
    (do ((n 0 (+ n 1))
         (o l (cdr o))
        )
    ((null o) n)
    )
  )
```
Die Variable "o" fungiert hier als rest der Liste, welche sich in der "do-Schleife" mit jedem Schritt mit Hilfe von "cdr" bis auf null verkleinert.

d) my-lengthR:
```lisp  
   (defun my-lengthR (l)
     (cond ((null l) 0)
       ((listp (car l)) (+ (my-lengthR (car l)) (my-lengthR (cdr l))))
       (t (+ 1 (my-lengthR (cdr l))))
     )
   )
```

(e) my-reverse:
```lisp  
  (defun my-reverse (l)
    (do ((n (- (list-length l) 1) (- n 1) )
    (l2 () (append l2 (list (nth n 1)))))
    ((= n -1) l2)
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
 
 
 
 
