(ql:quickload "lispbuilder-sdl")

(defvar k 517)

(defun main (argv)
  (if argv () ())
  (sdl:enable-unicode)
  (sdl:unicode-enabled-p)
  (print (char k))
  (sb-ext:exit))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
