# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	DEBIAN_POOL/apt-cacher-ng
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	keve@keve.hu
COMMENT=	Specialized http/s proxy for caching software distribution sites

LICENSE=	EduardBloch
LICENSE_NAME=	Eduard Bloch license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:outsource tar:xz
USE_RC_SUBR=	apt_cacher_ng

OPTIONS_DEFINE=	SSL FUSE DOCS
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=	yes

SSL_DESC=	Include SSL support to allow proxying https sites
FUSE_DESC=	Include FUSE support enable interfacing with the proxy via the acngfs filesystem

SSL_USES=	ssl

FUSE_BUILD_DEPENDS=	pkg-config:devel/pkgconf
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs

CMAKE_ARGS+=	-DMANDIR:PATH=${PREFIX}/man

SSL_CMAKE_BOOL=		USE_SSL
SSL_CMAKE_ON=		-Dopenssl_FOUND=1 -Dopenssl_CFLAGS="-I ${OPENSSLINC}" -Dopenssl_LDFLAGS="-L ${OPENSSLLIB} -lssl -lcrypto"

FUSE_CMAKE_BOOL=	USE_FUSE

SUB_FILES=	backends_debian.sample backends_freebsd.sample backends_ubuntu.sample freebsd_mirrors Readme.FreeBSD

post-stage:
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/Readme.FreeBSD ${STAGEDIR}${DOCSDIR}
	${INSTALL} ${WRKDIR}/backends_debian.sample ${STAGEDIR}${PREFIX}/etc/apt-cacher-ng
	${INSTALL} ${WRKDIR}/backends_freebsd.sample ${STAGEDIR}${PREFIX}/etc/apt-cacher-ng
	${INSTALL} ${WRKDIR}/backends_ubuntu.sample ${STAGEDIR}${PREFIX}/etc/apt-cacher-ng
	${INSTALL_DATA} ${WRKDIR}/freebsd_mirrors ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/log/apt-cacher-ng

.include <bsd.port.mk>
