
(defvar roger 'string)

(defun map-test ()
  (print (map roger #'(lambda (x y)
	 (char "01234567890ABCDEF" (mod (+ x y) 16)))
	 '(0 2 3 4)
	 '(0 9 8 7))))

(defun main (argv)
  (print argv)
  (map-test)
  (sb-ext:exit))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
