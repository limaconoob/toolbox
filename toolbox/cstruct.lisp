
(asdf:load-system :cffi)

(cffi:defcstruct bonjour
  (coucou :int)
  (hello :unsigned-char))

(cffi:defcstruct coucou
  (:pointer (:struct bonjour)))

(sb-ext:exit)
