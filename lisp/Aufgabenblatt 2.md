# Arbeitsblatt 2




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
