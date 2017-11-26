# Arbeitsblatt 1



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
 
 
 
 
