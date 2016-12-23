(ql:quickload "lispbuilder-sdl")

(cffi:defcfun "strlen" :int
  (n :string))

;(cffi:defcfun "ssl_read" :int
;  (ssl :pointer) (buf :pointer) (len :int))

;(cffi:defcfun "open" :int
;  (path :pointer))

;(cffi:defcfun "close" :int
;  (fdes :int))

(defvar *stock* '())
(defvar fdes :int)

(defun main (argv)
  (if argv () ())
  (setq fdes (open "./test.txt"))
  (print (open "./test.txt"))
  (print (read t *stock*))
  (print (read fdes *stock*))
  (print (read fdes *stock*))
  (print (read fdes))
  (print fdes)
  (sb-ext:exit))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
