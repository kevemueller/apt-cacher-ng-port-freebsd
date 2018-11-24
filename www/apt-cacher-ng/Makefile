# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	DEBIAN_POOL/apt-cacher-ng
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	keve@keve.hu
COMMENT=	Specialized http/s proxy for caching software distribution sites

LICENSE=	EduardBloch
LICENSE_NAME=   Eduard Bloch license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:outsource tar:xz
USE_RC_SUBR=	apt_cacher_ng

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	SSL FUSE DOCS #LIBWRAP
OPTIONS_SUB=	yes

SSL_DESC=	Include SSL support to allow proxying https sites.
#LIBWRAP_DESC=	Include libwrap support.
FUSE_DESC=	Include FUSE support.

OPTIONS_DEFAULT=	SSL DOCS

SSL_USES=		ssl
#SSL_BUILD_DEPENDS=	pkg-config:devel/pkgconf
#SSL_BUILD_DEPENDS=	pkg-config:devel/pkgconf openssl:security/openssl
#SSL_LIB_DEPENDS=	libcrypto.so:security/openssl

#LIBWRAP_LIB_DEPENDS=	libwrap.so:...
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs

CMAKE_ARGS+=	-DMANDIR:PATH=${PREFIX}/man

SSL_CMAKE_BOOL=		USE_SSL
FUSE_CMAKE_BOOL=	USE_FUSE
SSL_CMAKE_ON=		-Dopenssl_FOUND=1 -Dopenssl_CFLAGS="-I ${OPENSSLINC}" -Dopenssl_LDFLAGS="-L ${OPENSSLLIB} -lssl -lcrypto"

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
