 

(defvar *the* (list 0 1 2 3 4))

(defun coucou (hey)
  (cond
    ((null hey) ())
    (T  (print (car hey))
        (car hey)
        (coucou (cdr hey)))))

(coucou *the*)
(sb-ext:exit)
