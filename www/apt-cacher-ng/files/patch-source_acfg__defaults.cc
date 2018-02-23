--- source/acfg_defaults.cc.orig	2017-11-05 19:54:13 UTC
+++ source/acfg_defaults.cc
@@ -39,6 +39,9 @@ string pfilepat(".*(\\.(u|d)?deb|\\.rpm|
     "|/dists/.*/by-hash/.*" // support Debian/Ubuntu by-hash index files
     "|\\.asc$" // all remaining PGP signatures. Assuming that volatile ones are matched below.
     "|changelogs/pool/.*/changelog.txt$" // packages.ultimediaos.com
+    "|(base|doc|games|kernel|lib32|ports|src)\\.txz$" // FreeBSD releases
+    "|(packagesite|meta)\\.txz?$" // FreeBSD packagesite
+    "|\\.txz(\\.sig)?$" // FreeBSD package/signature
 ")$");
 
 string svfilepat("/development/rawhide/.*"
