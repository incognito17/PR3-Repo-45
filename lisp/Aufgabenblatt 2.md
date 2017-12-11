# Arbeitsblatt 2



**Size:**
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
**isEmpty:**
```Lisp  
      (defun isEmpty (l)
            (cond
                  ((not(listp l)) nil)
                  ((not(null l)) nil)
                  (t (True))
            )
      )
```

**getMin:**

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
rekursiv:
```Lisp

      (defun minimum (l)
        (cond
            ((null l) nil)
            ((null (cadr l))(car l))
            (t(getMin (cadr l)))
        )
      )
```

**getMax:**

iterativ:
```Lisp
      (defun maximum (l)
                   (loop 
                    (setq r (car l))
                    (setq l (caddr l))
                    (cond ((null l) (return r))
                   )
       )
```
rekursiv:
```Lisp
     (defun getMax (l)
            (cond
                  ((null l) nil)
                  ((null (caddr l))(car l))
                  (t (getMax (caddr l)))))
```

**contains:**
```Lisp
     (defun contains (a l)
              (cond
               ((null (car l)) nil)
               ((eq a (car l)) (True))
               ((< a (car l)) (if (null (cadr l))
                                nil
                              (contains a (cadr l))))
               ((> a (car l)) (if (null (caddr l))
                                  nil
                                (contains a (caddr l))))
              )
     )
```

**insert:**
```Lisp
     (defun insert (a l)
              (cond
               ((null (car l)) (setf  (car l) (list  a () ())))
               ((< a (car l)) (if (null (cadr l))
                                  (setf (cadr l) (list a () ()))
                                (insert a (cadr l))))
               ((> a (car l)) (if (null (caddr l))
                                  (setf (caddr l) (list a () ()))
                                (insert a (caddr l))))
              )
      )
```
