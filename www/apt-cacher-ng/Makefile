# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	3.1
CATEGORIES=	www
MASTER_SITES=	DEBIAN_POOL/apt-cacher-ng
#DISTFILES=	apt-cacher-ng_3.1.orig.tar.xz
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	keve@keve.hu
COMMENT=	Specialized http/s proxy for caching software distribution sites

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource tar:xz ssl
USE_RC_SUBR=	apt_cacher_ng

OPTIONS_DEFINE=	SSL FUSE DOCS #LIBWRAP
OPTIONS_SUB=	yes

SSL_DESC=	Include SSL support to allow proxying https sites.
#LIBWRAP_DESC=	Include libwrap support.
FUSE_DESC=	Include FUSE support.

OPTIONS_DEFAULT=	SSL DOCS

DEFAULT_VERSIONS+=	ssl=openssl

SSL_BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf openssl:${PORTSDIR}/security/openssl
SSL_LIB_DEPENDS=	libcrypto.so:${PORTSDIR}/security/openssl
#LIBWRAP_LIB_DEPENDS=	libwrap.so:${PORTSDIR}/...
FUSE_LIB_DEPENDS=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs

CMAKE_ARGS+=	-DMANDIR:PATH=${PREFIX}/man

SSL_CMAKE_ON=	-DUSE_SSL:BOOL=ON
SSL_CMAKE_OFF=	-DUSE_SSL:BOOL=OFF
FUSE_CMAKE_ON=	-DUSE_FUSE:BOOL=ON
FUSE_CMAKE_OFF=	-DUSE_FUSE:BOOL=OFF

SUB_FILES=	backends_debian backends_freebsd backends_ubuntu freebsd_mirrors Readme.FreeBSD

post-stage:
	${INSTALL_MAN} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/Readme.FreeBSD ${STAGEDIR}${DOCSDIR}
	${INSTALL} ${WRKDIR}/backends_debian ${STAGEDIR}${PREFIX}/etc/apt-cacher-ng
	${INSTALL} ${WRKDIR}/backends_freebsd ${STAGEDIR}${PREFIX}/etc/apt-cacher-ng
	${INSTALL} ${WRKDIR}/backends_ubuntu ${STAGEDIR}${PREFIX}/etc/apt-cacher-ng
	${INSTALL_DATA} ${WRKDIR}/freebsd_mirrors ${STAGEDIR}${PREFIX}/lib/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/log/apt-cacher-ng

.include <bsd.port.mk>
