*** source/acfg_defaults.cc.orig	Thu Feb 22 16:53:14 2018
--- source/acfg_defaults.cc	Thu Feb 22 16:53:52 2018
***************
*** 39,44 ****
--- 39,47 ----
      "|/dists/.*/by-hash/.*" // support Debian/Ubuntu by-hash index files
      "|\\.asc$" // all remaining PGP signatures. Assuming that volatile ones are matched below.
      "|changelogs/pool/.*/changelog.txt$" // packages.ultimediaos.com
+     "|(base|doc|games|kernel|lib32|ports|src)\\.txz$" // FreeBSD releases
+     "|(packagesite|meta)\\.txz?$" // FreeBSD packagesite
+     "|\\.txz(\\.sig)?$" // FreeBSD package/signature
  ")$");
  
  string svfilepat("/development/rawhide/.*"
