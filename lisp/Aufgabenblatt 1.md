# Arbeitsblatt 1





* Postorder
```lisp  
  (defun postorder (l)
                   (cond
                      ((or (not (listp l)) (null l)) nil)
                      ((and (null (cadr l)) (null (caddr l))) l)
                      (t (append (derevo2 (cadr l)) (derevo2 (caddr l)) (list (car l))))
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
 
 
