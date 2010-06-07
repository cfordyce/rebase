;; .emacs
;;
;; NOTE:  THIS FILE IS FOR XEMACS AND SHOULD BE SAVED AS: ~/.xemacs/init.el

;;; uncomment this line to disable loading of "default.el" at startup
;; (setq inhibit-default-init t)

;; enable visual feedback on selections
;(setq transient-mark-mode t)

;; default to better frame titles
(setq frame-title-format
      (concat  "%b - emacs@" (system-name)))

;; default to unified diffs
(setq diff-switches "-u")

;; always end a file with a newline
;(setq require-final-newline 'query)


(custom-set-variables
 '(mouse-yank-at-point t)
 '(paren-mode (quote sexp) nil (paren))
 '(toolbar-captioned-p nil)
 '(toolbar-visible-p nil))

(custom-set-faces
 '(default ((t (:size "12pt" :family "Lucidatypewriter"))) t))

