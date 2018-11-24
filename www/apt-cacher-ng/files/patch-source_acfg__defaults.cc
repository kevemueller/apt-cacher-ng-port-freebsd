--- source/acfg_defaults.cc.orig	2018-09-07 13:02:18 UTC
+++ source/acfg_defaults.cc
@@ -40,6 +40,9 @@ string pfilepat(".*(\\.(u|d)?deb|\\.rpm|
     "|\\.asc$" // all remaining PGP signatures. Assuming that volatile ones are matched below.
     "|changelogs/pool/.*/changelog.txt$" // packages.ultimediaos.com
     "|/objects/.*/.*\\.(dirtree|filez|commit|commitmeta)|/repo/deltas/.*" // FlatPak
+    "|(base|doc|games|kernel|lib32|ports|src)\\.txz$" // FreeBSD releases
+    "|(packagesite|meta)\\.txz?$" // FreeBSD packagesite
+    "|\\.txz(\\.sig)?$" // FreeBSD package/signature
 ")$");
 
 string svfilepat("/development/rawhide/.*"
