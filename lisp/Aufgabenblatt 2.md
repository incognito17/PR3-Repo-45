# Arbeitsblatt 2



**Size:
```Lisp  
      (defun size (l)
           (cond 
                ((null l) 0)
                ((and (null (cadr l)) (null (caddr l))) 1)
                ((null (cadr l)) (+ 1 (size (caddr l))))
                ((null (caddr l)) (+ 1 (size (cadr l))))
                (t (+ 1 (size (cadr l)) (size (caddr l))))
            )
      )
```
isEmpty:
```Lisp  
      (defun isEmpty (l)
            (cond
                  ((not(listp l)) nil)
                  ((not(null l)) nil)
                  (t (True))
            )
      )
```
getMin: 

iterativ:
```Lisp
      (defun minimum (l)
                  (loop 
                    (setq r (car l))
                    (setq l (cadr l))
                    (cond ((null l) (return r)))
                   )
      )
```

```Lisp
      (defun minimum (l)
                  (loop 
                    (setq r (car l))
                    (setq l (cadr l))
                    (cond ((null l) (return r)))
                   )
      )
```

```Lisp
      (defun maximum (l)
                   (loop 
                    (setq r (car l))
                    (setq l (caddr l))
                    (cond ((null l) (return r))
                   )
       )
```

