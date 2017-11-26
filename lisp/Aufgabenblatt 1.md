# Arbeitsblatt 1

## Baum-Darstellung
Man kann einen binären Baum als Liste folgendermaßen darstellen:

Den Wurzelknoten kann man als das erste Element der Liste wählen, den linken Unterbaum beispielsweise als zweiten und den rechten Unterbaum als dritten und letzten Element.

Für alle anderen Teilbäume, kann man dieses Schema beibehalten, sodass sich immer für jeweils einen (Teil)Baum eine Liste der Länge 3 ergibt. (Falls der Baum nur einen rechten bzw. nur einen linken Teilbaum hat, kann man für den fehlenden Unterbaum eine leere Liste als Element übergeben).

Beispiel: 

[![Baum](https://github.com/pr3-lecture/repo-45/blob/master/lisp/drv01.png)](http://jquery.com/)

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
 
 
 
 
