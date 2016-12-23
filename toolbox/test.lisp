(defun elements-are-of-type (seq type)
    (every #'(lambda (x) (typep x type)) seq))

(deftype list-of-type (type)
    (let ((predicate (gensym)))
          (setf (symbol-function predicate)
                      #'(lambda (seq) (elements-are-of-type seq type)) )
              `(and list (satisfies ,predicate)) ))

(print (typep '(1 2 3) '(list-of-type integer)))
; -> T

(print (typep '(1 2 a) '(list-of-type integer)))
; -> NIL

(print (typep '(a b c) '(list-of-type symbol)))
; -> T

(sb-ext:exit)
