(ql:quickload "lispbuilder-sdl")

(defvar k 0)

(defun main (argv)
  (setq k 0)
  (loop for c across (cadr argv)
    do (if (eq c #\)) (setq k (- k 1)) ())
	   (if (eq c #\() (setq k (+ k 1)) ()))
  (print k)
  (loop for c across (cadr argv)
	do (if (atom c) (princ c) ()))
  (if (> k 0)
	(loop for i from 1 to k by 1
	   do (princ #\))))
  (sb-ext:exit))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
