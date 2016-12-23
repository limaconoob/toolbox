(defconstant +upper-left+ 0 )
(defconstant +upper-middle+ 1 )
(defconstant +upper-right+ 2 )
(defconstant +middle-left+ 3 )
(defconstant +middle-central+ 4 )
(defconstant +middle-right+ 5 )
(defconstant +lower-left+ 6 )
(defconstant +lower-middle+ 7 )
(defconstant +lower-right+ 8 )

(defvar *position* (list +upper-left+ +upper-middle+ +upper-right+ +middle-left+ +middle-central+ +middle-right+ +lower-left+ +lower-middle+ +lower-right+))

(defun finder (pattern liste)
  (cond
    ((null liste) 'false)
    (T  (if (= (car liste) pattern)
          'true
        (finder pattern (cdr liste))))))

(print (finder 3 *position*))
(print (finder 12 *position*))
(print (finder 0 *position*))
(sb-ext:exit)
