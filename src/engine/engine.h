#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "cube.h"
#include "world.h"

#ifndef STANDALONE

#include "octa.h"
#include "light.h"
#include "bih.h"
#include "texture.h"
#include "model.h"

// GL_ARB_multitexture
extern PFNGLACTIVETEXTUREARBPROC       glActiveTexture_;
extern PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTexture_;
extern PFNGLMULTITEXCOORD2FARBPROC     glMultiTexCoord2f_;
extern PFNGLMULTITEXCOORD3FARBPROC     glMultiTexCoord3f_;
extern PFNGLMULTITEXCOORD4FARBPROC     glMultiTexCoord4f_;

// GL_ARB_vertex_buffer_object
extern PFNGLGENBUFFERSARBPROC       glGenBuffers_;
extern PFNGLBINDBUFFERARBPROC       glBindBuffer_;
extern PFNGLMAPBUFFERARBPROC        glMapBuffer_;
extern PFNGLUNMAPBUFFERARBPROC      glUnmapBuffer_;
extern PFNGLBUFFERDATAARBPROC       glBufferData_;
extern PFNGLBUFFERSUBDATAARBPROC    glBufferSubData_;
extern PFNGLDELETEBUFFERSARBPROC    glDeleteBuffers_;
extern PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubData_;

// GL_ARB_occlusion_query
extern PFNGLGENQUERIESARBPROC        glGenQueries_;
extern PFNGLDELETEQUERIESARBPROC     glDeleteQueries_;
extern PFNGLBEGINQUERYARBPROC        glBeginQuery_;
extern PFNGLENDQUERYARBPROC          glEndQuery_;
extern PFNGLGETQUERYIVARBPROC        glGetQueryiv_;
extern PFNGLGETQUERYOBJECTIVARBPROC  glGetQueryObjectiv_;
extern PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuiv_;

// GL_EXT_timer_query
#ifndef GL_EXT_timer_query
#define GL_TIME_ELAPSED_EXT               0x88BF
typedef llong GLint64EXT;
typedef ullong GLuint64EXT;
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VEXTPROC) (GLuint id, GLenum pname, GLint64EXT *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VEXTPROC) (GLuint id, GLenum pname, GLuint64EXT *params);
#endif
extern PFNGLGETQUERYOBJECTI64VEXTPROC glGetQueryObjecti64v_;
extern PFNGLGETQUERYOBJECTUI64VEXTPROC glGetQueryObjectui64v_;

// GL_EXT_framebuffer_object
extern PFNGLBINDRENDERBUFFEREXTPROC        glBindRenderbuffer_;
extern PFNGLDELETERENDERBUFFERSEXTPROC     glDeleteRenderbuffers_;
extern PFNGLGENFRAMEBUFFERSEXTPROC         glGenRenderbuffers_;
extern PFNGLRENDERBUFFERSTORAGEEXTPROC     glRenderbufferStorage_;
extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC  glCheckFramebufferStatus_;
extern PFNGLBINDFRAMEBUFFEREXTPROC         glBindFramebuffer_;
extern PFNGLDELETEFRAMEBUFFERSEXTPROC      glDeleteFramebuffers_;
extern PFNGLGENFRAMEBUFFERSEXTPROC         glGenFramebuffers_;
extern PFNGLFRAMEBUFFERTEXTURE1DEXTPROC    glFramebufferTexture1D_;
extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC    glFramebufferTexture2D_;
extern PFNGLFRAMEBUFFERTEXTURE3DEXTPROC    glFramebufferTexture3D_;
extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbuffer_;
extern PFNGLGENERATEMIPMAPEXTPROC          glGenerateMipmap_;

// GL_ARB_draw_buffers
extern PFNGLDRAWBUFFERSARBPROC glDrawBuffers_;

// GL_EXT_framebuffer_blit
#ifndef GL_EXT_framebuffer_blit
#define GL_READ_FRAMEBUFFER_EXT           0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT           0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT   0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT   0x8CAA
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFEREXTPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif
extern PFNGLBLITFRAMEBUFFEREXTPROC         glBlitFramebuffer_;

// GL_EXT_draw_range_elements
extern PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElements_;

// GL_EXT_blend_minmax
extern PFNGLBLENDEQUATIONEXTPROC glBlendEquation_;

// GL_EXT_blend_color
extern PFNGLBLENDCOLOREXTPROC glBlendColor_;

// GL_EXT_multi_draw_arrays
extern PFNGLMULTIDRAWARRAYSEXTPROC   glMultiDrawArrays_;
extern PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElements_;

// GL_EXT_packed_depth_stencil
#ifndef GL_DEPTH_STENCIL_EXT
#define GL_DEPTH_STENCIL_EXT 0x84F9
#endif
#ifndef GL_DEPTH24_STENCIL8_EXT
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#endif
#ifndef GL_UNSIGNED_INT_24_8_EXT
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#endif

// GL_EXT_packed_float
#ifndef GL_R11F_G11F_B10F_EXT
#define GL_R11F_G11F_B10F_EXT 0x8C3A
#endif

// GL_ARB_texture_compression
extern PFNGLCOMPRESSEDTEXIMAGE3DARBPROC    glCompressedTexImage3D_;
extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC    glCompressedTexImage2D_;
extern PFNGLCOMPRESSEDTEXIMAGE1DARBPROC    glCompressedTexImage1D_;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3D_;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2D_;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1D_;
extern PFNGLGETCOMPRESSEDTEXIMAGEARBPROC   glGetCompressedTexImage_;

// GL_ARB_texture_rg
#ifndef GL_ARB_texture_rg
#define GL_RG                             0x8227
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#endif

// GL_EXT_depth_bounds_test
extern PFNGLDEPTHBOUNDSEXTPROC glDepthBounds_;

// GL_ARB_color_buffer_float
extern PFNGLCLAMPCOLORARBPROC glClampColor_;

// GL_EXT_texture3D
extern PFNGLTEXIMAGE3DEXTPROC        glTexImage3D_;
extern PFNGLTEXSUBIMAGE3DEXTPROC     glTexSubImage3D_;
extern PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3D_;

extern void glerror(const char *file, int line, GLenum error);

#define GLERROR do { GLenum error = glGetError(); if(error != GL_NO_ERROR) glerror(__FILE__, __LINE__, error); } while(0)

#include "varray.h"

extern dynent *player;
extern physent *camera1;                // special ent that acts as camera, same object as player1 in FPS mode

extern int worldscale, worldsize;
extern int mapversion;
extern char *maptitle;
extern vector<ushort> texmru;
extern int xtraverts, xtravertsva;
extern const ivec cubecoords[8];
extern const ivec facecoords[6][4];
extern const uchar fv[6][4];
extern const uchar fvmasks[64];
extern const uchar faceedgesidx[6][4];
extern bool inbetweenframes, renderedframe;

extern SDL_Surface *screen;
extern int zpass, glowpass;

extern vector<int> entgroup;

// rendertext
struct font
{
    struct charinfo
    {
        short x, y, w, h, offsetx, offsety, advance, tex;
    };

    char *name;
    vector<Texture *> texs;
    vector<charinfo> chars;
    int charoffset, defaultw, defaulth, scale;

    font() : name(NULL) {}
    ~font() { DELETEA(name); }
};

#define FONTH (curfont->scale)
#define FONTW (FONTH/2)
#define MINRESW 640
#define MINRESH 480

extern font *curfont;

// texture
extern int hwtexsize, hwcubetexsize, hwmaxaniso, maxtexsize;

extern Texture *textureload(const char *name, int clamp = 0, bool mipit = true, bool msg = true);
extern int texalign(const void *data, int w, int bpp);
extern bool floatformat(GLenum format);
extern void cleanuptexture(Texture *t);
extern void loadalphamask(Texture *t);
extern Texture *cubemapload(const char *name, bool mipit = true, bool msg = true, bool transient = false);
extern void drawcubemap(int size, const vec &o, float yaw, float pitch, const cubemapside &side);
extern void loadshaders();
extern void setuptexparameters(int tnum, const void *pixels, int clamp, int filter, GLenum format = GL_RGB, GLenum target = GL_TEXTURE_2D);
extern void createtexture(int tnum, int w, int h, const void *pixels, int clamp, int filter, GLenum component = GL_RGB, GLenum target = GL_TEXTURE_2D, int pw = 0, int ph = 0, int pitch = 0, bool resize = true, GLenum format = GL_FALSE);
extern void create3dtexture(int tnum, int w, int h, int d, const void *pixels, int clamp, int filter, GLenum component = GL_RGB, GLenum target = GL_TEXTURE_3D_EXT);
extern void blurtexture(int n, int bpp, int w, int h, uchar *dst, const uchar *src, int margin = 0);
extern void blurnormals(int n, int w, int h, bvec *dst, const bvec *src, int margin = 0);
extern void renderpostfx();
extern void initenvmaps();
extern void genenvmaps();
extern ushort closestenvmap(const vec &o);
extern ushort closestenvmap(int orient, int x, int y, int z, int size);
extern GLuint lookupenvmap(ushort emid);
extern GLuint lookupenvmap(Slot &slot);
extern bool reloadtexture(Texture &tex);
extern bool reloadtexture(const char *name);
extern void setuptexcompress();
extern void clearslots();
extern void compacteditvslots();
extern void compactmruvslots();
extern void compactvslots(cube *c, int n = 8);
extern void compactvslot(int &index);
extern int compactvslots();

// pvs
extern void clearpvs();
extern bool pvsoccluded(const ivec &bborigin, const ivec &bbsize);
extern bool pvsoccludedsphere(const vec &center, float radius);
extern bool waterpvsoccluded(int height);
extern void setviewcell(const vec &p);
extern void savepvs(stream *f);
extern void loadpvs(stream *f, int numpvs);
extern int getnumviewcells();

static inline bool pvsoccluded(const ivec &bborigin, int size)
{
    return pvsoccluded(bborigin, ivec(size, size, size));
}

// rendergl
extern bool hasVBO, hasDRE, hasOQ, hasTR, hasT3D, hasFBO, hasAFBO, hasDS, hasTF, hasCBF, hasBE, hasBC, hasCM, hasNP2, hasTC, hasMT, hasAF, hasMDA, hasGLSL, hasGM, hasNVFB, hasSGIDT, hasSGISH, hasDT, hasSH, hasNVPCF, hasPBO, hasFBB, hasUBO, hasBUE, hasDB, hasTG, hasT4, hasTQ, hasPF, hasTRG, hasDBT, hasDC;
extern int hasstencil;
extern int glslversion;

extern int vieww, viewh;
extern float curfov, fovy, aspect;
extern float nearplane;
extern int farplane;
extern int hdr;
extern bool hdrfloat;
extern float ldrscale, ldrscaleb;
extern bool envmapping;
extern int minimapping;
extern const glmatrixf viewmatrix;
extern glmatrixf mvmatrix, projmatrix, mvpmatrix, invmvmatrix, invmvpmatrix, eyematrix, worldmatrix;
extern bvec fogcolor;

extern void gl_checkextensions();
extern void gl_init(int w, int h, int bpp, int depth, int fsaa);
extern void cleangl();
extern void invalidatepostfx();
extern void gl_setupframe(int w, int h);
extern void gl_drawframe(int w, int h);
extern void gl_drawmainmenu(int w, int h);
extern void drawminimap();
extern void enablepolygonoffset(GLenum type);
extern void disablepolygonoffset(GLenum type);
extern bool calcspherescissor(const vec &center, float size, float &sx1, float &sy1, float &sx2, float &sy2);
extern bool calcbbscissor(const ivec &bbmin, const ivec &bbmax, float &sx1, float &sy1, float &sx2, float &sy2);
extern int pushscissor(float sx1, float sy1, float sx2, float sy2);
extern void popscissor();
extern void screenquad(float sw, float sh);
extern void screenquad(float sw, float sh, float sw2, float sh2);
extern void recomputecamera();
extern void findorientation();
extern void writecrosshairs(stream *f);

// renderextras
extern void render3dbox(vec &o, float tofloor, float toceil, float xradius, float yradius = 0);

// octa
extern cube *newcubes(uint face = F_EMPTY, int mat = MAT_AIR);
extern cubeext *growcubeext(cubeext *ext, int maxverts);
extern void setcubeext(cube &c, cubeext *ext);
extern cubeext *newcubeext(cube &c, int maxverts = 0, bool init = true);
extern void getcubevector(cube &c, int d, int x, int y, int z, ivec &p);
extern void setcubevector(cube &c, int d, int x, int y, int z, const ivec &p);
extern int familysize(cube &c);
extern void freeocta(cube *c);
extern void discardchildren(cube &c, bool fixtex = false, int depth = 0);
extern void optiface(uchar *p, cube &c);
extern void validatec(cube *c, int size = 0);
extern bool isvalidcube(cube &c);
extern ivec lu;
extern int lusize;
extern cube &lookupcube(int tx, int ty, int tz, int tsize = 0, ivec &ro = lu, int &rsize = lusize);
extern cube *neighbourstack[32];
extern int neighbourdepth;
extern cube &neighbourcube(cube &c, int orient, int x, int y, int z, int size, ivec &ro = lu, int &rsize = lusize);
extern void resetclipplanes();
extern int getmippedtexture(cube &p, int orient);
extern void forcemip(cube &c, bool fixtex = true);
extern bool subdividecube(cube &c, bool fullcheck=true, bool brighten=true);
extern void edgespan2vectorcube(cube &c);
extern int faceconvexity(ivec v[4]);
extern int faceconvexity(ivec v[4], int &vis);
extern int faceconvexity(vertinfo *verts, int numverts);
extern int faceconvexity(cube &c, int orient);
extern void calcvert(cube &c, int x, int y, int z, int size, ivec &vert, int i, bool solid = false);
extern void calcvert(cube &c, int x, int y, int z, int size, vec &vert, int i, bool solid = false);
extern uint faceedges(cube &c, int orient);
extern bool collapsedface(cube &c, int orient);
extern bool touchingface(cube &c, int orient);
extern bool flataxisface(cube &c, int orient);
extern bool collideface(cube &c, int orient);
extern int genclipplane(cube &c, int i, vec *v, plane *clip);
extern void genclipplanes(cube &c, int x, int y, int z, int size, clipplanes &p);
extern bool visibleface(cube &c, int orient, int x, int y, int z, int size, uchar mat = MAT_AIR, uchar nmat = MAT_AIR, uchar matmask = MATF_VOLUME);
extern int visibletris(cube &c, int orient, int x, int y, int z, int size, uchar nmat = MAT_AIR, uchar matmask = MAT_AIR);
extern int visibleorient(cube &c, int orient);
extern void genfaceverts(cube &c, int orient, ivec v[4]);
extern int calcmergedsize(int orient, const ivec &co, int size, const vertinfo *verts, int numverts);
extern void invalidatemerges(cube &c, const ivec &co, int size, bool msg);
extern void calcmerges();

extern int mergefaces(int orient, facebounds *m, int sz);
extern void mincubeface(cube &cu, int orient, const ivec &o, int size, const facebounds &orig, facebounds &cf, uchar nmat = MAT_AIR, uchar matmask = MATF_VOLUME);

static inline uchar octantrectangleoverlap(const ivec &c, int size, const ivec &o, const ivec &s)
{
    uchar p = 0xFF; // bitmask of possible collisions with octants. 0 bit = 0 octant, etc
    ivec v(c);
    v.add(size);
    if(v.z <= o.z)     p &= 0xF0; // not in a -ve Z octant
    else if(v.z >= o.z+s.z) p &= 0x0F; // not in a +ve Z octant
    if(v.y <= o.y)     p &= 0xCC; // not in a -ve Y octant
    else if(v.y >= o.y+s.y) p &= 0x33; // etc..
    if(v.x <= o.x)     p &= 0xAA;
    else if(v.x >= o.x+s.x) p &= 0x55;
    return p;
}

static inline cubeext &ext(cube &c)
{
    return *(c.ext ? c.ext : newcubeext(c));
}

// shadowmap

#define LIGHTTILE_W 10
#define LIGHTTILE_H 10

static inline void masktiles(uint *tiles, float sx1, float sy1, float sx2, float sy2)
{
    int tx1 = max(int(floor((sx1 + 1)*0.5f*LIGHTTILE_W)), 0), ty1 = max(int(floor((sy1 + 1)*0.5f*LIGHTTILE_H)), 0),
        tx2 = min(int(ceil((sx2 + 1)*0.5f*LIGHTTILE_W)), LIGHTTILE_W), ty2 = min(int(ceil((sy2 + 1)*0.5f*LIGHTTILE_H)), LIGHTTILE_H);
    for(int ty = ty1; ty < ty2; ty++) tiles[ty] |= ((1<<(tx2-tx1))-1)<<tx1;
}

enum { SM_NONE = 0, SM_REFLECT, SM_CUBEMAP, SM_TETRA, SM_CASCADE, SM_SPOT };
 
extern int shadowmapping;

extern int smtetra, smtetraclip;
extern plane smtetraclipplane;

extern vec shadoworigin, shadowdir;
extern float shadowradius, shadowbias;
extern int shadowside, shadowspot;

extern void collectlights();

extern void findshadowvas();
extern void findshadowmms();

extern void renderrsmgeom();
extern void rendershadowmapworld();
extern void batchshadowmapmodels();

extern int calcbbtetramask(const vec &bbmin, const vec &bbmax, const vec &lightpos, float lightradius, float bias);
extern int calcbbsidemask(const vec &bbmin, const vec &bbmax, const vec &lightpos, float lightradius, float bias);
extern int calcspheresidemask(const vec &p, float radius, float bias);
extern int calcspheretetramask(const vec &p, float radius, float bias);
extern int cullfrustumsides(const vec &lightpos, float lightradius, float size, float border);
extern int cullfrustumtetra(const vec &lightpos, float lightradius, float size, float border);
extern int calcbbcsmsplits(const ivec &bbmin, const ivec &bbmax);
extern int calcspherecsmsplits(const vec &center, float radius);
extern int calcbbrsmsplits(const ivec &bbmin, const ivec &bbmax);
extern int calcspherersmsplits(const vec &center, float radius);

static inline bool sphereinsidespot(const vec &dir, int spot, const vec &center, float radius)
{
    const vec2 &sc = sincos360[spot];
    float cdist = dir.dot(center), cradius = radius + sc.y*cdist;
    return sc.x*sc.x*(center.dot(center) - cdist*cdist) <= cradius*cradius;
}
static inline bool bbinsidespot(const vec &origin, const vec &dir, int spot, const ivec &bbmin, const ivec &bbmax)
{
    vec radius = ivec(bbmax).sub(bbmin).tovec().mul(0.5f), center = bbmin.tovec().add(radius);
    return sphereinsidespot(dir, spot, center.sub(origin), radius.magnitude());
}

extern void loaddeferredlightshaders();
extern void cleardeferredlightshaders();

extern void clearshadowcache();

// ents
extern char *entname(entity &e);
extern bool haveselent();
extern undoblock *copyundoents(undoblock *u);
extern void pasteundoents(undoblock *u);

// octaedit
extern void cancelsel();
extern void rendertexturepanel(int w, int h);
extern void addundo(undoblock *u);
extern void commitchanges(bool force = false);
extern void rendereditcursor();
extern void tryedit();

// octarender
extern ivec worldmin, worldmax;
extern vector<tjoint> tjoints;

extern ushort encodenormal(const vec &n);
extern vec decodenormal(ushort norm);
extern void reduceslope(ivec &n);
extern void findtjoints();
extern void octarender();
extern void allchanged(bool load = false);
extern void clearvas(cube *c);
extern vtxarray *newva(int x, int y, int z, int size);
extern void destroyva(vtxarray *va, bool reparent = true);
extern bool readva(vtxarray *va, ushort *&edata, uchar *&vdata);
extern void updatevabb(vtxarray *va, bool force = false);
extern void updatevabbs(bool force = false);

// renderva

extern int oqfrags;
extern float alphafrontsx1, alphafrontsx2, alphafrontsy1, alphafrontsy2, alphabacksx1, alphabacksx2, alphabacksy1, alphabacksy2, alpharefractsx1, alpharefractsx2, alpharefractsy1, alpharefractsy2;
extern uint alphatiles[LIGHTTILE_H];

extern void visiblecubes(bool cull = true);
extern void setvfcP(const vec &bbmin = vec(-1, -1, -1), const vec &bbmax = vec(1, 1, 1));
extern void savevfcP();
extern void restorevfcP();
extern void rendergeom();
extern int findalphavas();
extern void renderrefractmask();
extern void renderalphageom(int side);
extern void rendermapmodels();
extern void renderoutline();

extern bool isfoggedsphere(float rad, const vec &cv);
extern int isvisiblesphere(float rad, const vec &cv);
extern bool bboccluded(const ivec &bo, const ivec &br);
extern occludequery *newquery(void *owner);
extern bool checkquery(occludequery *query, bool nowait = false);
extern void resetqueries();
extern int getnumqueries();
extern void drawbb(const ivec &bo, const ivec &br, const vec &camera = camera1->o);

#define startquery(query) do { glBeginQuery_(GL_SAMPLES_PASSED_ARB, ((occludequery *)(query))->id); } while(0)
#define endquery(query) \
    do { \
        glEndQuery_(GL_SAMPLES_PASSED_ARB); \
        extern int ati_oq_bug; \
        if(ati_oq_bug) glFlush(); \
    } while(0)

// dynlight

extern void updatedynlights();
extern int finddynlights();
extern bool getdynlight(int n, vec &o, float &radius, vec &color);

// material

extern float matliquidsx1, matliquidsy1, matliquidsx2, matliquidsy2;
extern float matsolidsx1, matsolidsy1, matsolidsx2, matsolidsy2;
extern float matrefractsx1, matrefractsy1, matrefractsx2, matrefractsy2;
extern uint matliquidtiles[LIGHTTILE_H], matsolidtiles[LIGHTTILE_H];
extern vector<materialsurface> editsurfs, glasssurfs, watersurfs, waterfallsurfs, lavasurfs, lavafallsurfs;
extern const vec matnormals[6];

extern int showmat;

extern int findmaterial(const char *name);
extern void genmatsurfs(cube &c, int cx, int cy, int cz, int size, vector<materialsurface> &matsurfs);
extern void calcmatbb(vtxarray *va, int cx, int cy, int cz, int size, vector<materialsurface> &matsurfs);
extern int optimizematsurfs(materialsurface *matbuf, int matsurfs);
extern void setupmaterials(int start = 0, int len = 0);
extern int findmaterials();
extern void rendermaterialmask();
extern void renderliquidmaterials();
extern void rendersolidmaterials();
extern void rendereditmaterials();
extern void renderminimapmaterials();
extern int visiblematerial(cube &c, int orient, int x, int y, int z, int size, uchar matmask = MATF_VOLUME);

// water
extern int vertwater, waterreflect, caustics, waterfog, waterdeep, lavafog;
extern bvec watercolor, waterdeepcolor, waterdeepfadecolor, waterfallcolor, lavacolor;
extern float watersx1, watersy1, watersx2, watersy2;

extern void renderwater();
extern void renderwaterfalls();
extern void renderlava();
extern void renderlava(const materialsurface &m, Texture *tex, float scale);
extern void loadcaustics(bool force = false);
extern void renderwaterfog(int mat, float blend);
extern void preloadwatershaders(bool force = false);

// server
extern vector<const char *> gameargs;

extern void initserver(bool listen, bool dedicated);
extern void cleanupserver();
extern void serverslice(bool dedicated, uint timeout);

extern ENetSocket connectmaster();
extern void localclienttoserver(int chan, ENetPacket *);
extern void localconnect();
extern bool serveroption(char *opt);

// serverbrowser
extern bool resolverwait(const char *name, ENetAddress *address);
extern int connectwithtimeout(ENetSocket sock, const char *hostname, const ENetAddress &address);
extern void addserver(const char *name, int port = 0, const char *password = NULL, bool keep = false);
extern void writeservercfg();

// client
extern void localdisconnect(bool cleanup = true);
extern void localservertoclient(int chan, ENetPacket *packet);
extern void connectserv(const char *servername, int port, const char *serverpassword);
extern void abortconnect();
extern void clientkeepalive();

// command
extern hashset<ident> idents;
extern int identflags;

extern void explodelist(const char *s, vector<char *> &elems, int limit = -1);
extern char *indexlist(const char *s, int pos);

extern void clearoverrides();
extern void writecfg(const char *name = NULL);

extern void checksleep(int millis);
extern void clearsleep(bool clearoverrides = true);

// console
extern void keypress(int code, bool isdown, int cooked);
extern int rendercommand(int x, int y, int w);
extern int renderconsole(int w, int h, int abovehud);
extern void conoutf(const char *s, ...);
extern void conoutf(int type, const char *s, ...);
extern void resetcomplete();
extern void complete(char *s, const char *cmdprefix);
const char *getkeyname(int code);
extern const char *addreleaseaction(char *s);
extern void writebinds(stream *f);
extern void writecompletions(stream *f);

// main
enum
{
    NOT_INITING = 0,
    INIT_LOAD,
    INIT_RESET
};
extern int initing;

enum
{
    CHANGE_GFX   = 1<<0,
    CHANGE_SOUND = 1<<1
};
extern bool initwarning(const char *desc, int level = INIT_RESET, int type = CHANGE_GFX);

extern void pushevent(const SDL_Event &e);
extern bool interceptkey(int sym);

extern float loadprogress;
extern void renderbackground(const char *caption = NULL, Texture *mapshot = NULL, const char *mapname = NULL, const char *mapinfo = NULL, bool restore = false, bool force = false);
extern void renderprogress(float bar, const char *text, GLuint tex = 0, bool background = false);

extern void getframemillis(float &avg, float &best, float &worst);
extern void getfps(int &fps, int &bestdiff, int &worstdiff);
extern void swapbuffers();
extern int getclockmillis();

// menu
extern void menuprocess();
extern void addchange(const char *desc, int type);
extern void clearchanges(int type);

// physics
extern void mousemove(int dx, int dy);
extern bool pointincube(const clipplanes &p, const vec &v);
extern bool overlapsdynent(const vec &o, float radius);
extern void rotatebb(vec &center, vec &radius, int yaw);
extern float shadowray(const vec &o, const vec &ray, float radius, int mode, extentity *t = NULL);
struct ShadowRayCache;
extern ShadowRayCache *newshadowraycache();
extern void freeshadowraycache(ShadowRayCache *&cache);
extern void resetshadowraycache(ShadowRayCache *cache);
extern float shadowray(ShadowRayCache *cache, const vec &o, const vec &ray, float radius, int mode, extentity *t = NULL);

// world

extern vector<int> outsideents;

extern void entcancel();
extern void entitiesinoctanodes();
extern void attachentities();
extern void freeoctaentities(cube &c);
extern bool pointinsel(selinfo &sel, vec &o);

extern void resetmap();
extern void startmap(const char *name);

// rendermodel
struct mapmodelinfo { string name; model *m; };

extern void findanims(const char *pattern, vector<int> &anims);
extern void loadskin(const char *dir, const char *altdir, Texture *&skin, Texture *&masks);
extern mapmodelinfo *getmminfo(int i);
extern void resetmodelbatches();
extern void startmodelquery(occludequery *query);
extern void endmodelquery();
extern void rendermodelbatches();
extern void shadowmaskbatchedmodels(bool dynshadow = true);
extern void rendermodelbatches();
extern void rendermapmodel(int idx, int anim, const vec &o, float yaw = 0, float pitch = 0, int flags = MDL_CULL_VFC | MDL_CULL_DIST, int basetime = 0, float size = 1);
extern void clearbatchedmapmodels();
extern void preloadmodelshaders();
extern void preloadusedmapmodels(bool msg = false, bool bih = false);
extern int batcheddynamicmodels();

// renderparticles
extern void particleinit();
extern void clearparticles();
extern void clearparticleemitters();
extern void seedparticles();
extern void updateparticles();
extern void renderparticles(bool mainpass = false);
extern bool printparticles(extentity &e, char *buf);

// decal
extern void initdecals();
extern void cleardecals();
extern void renderdecals(bool mainpass = false);

// rendersky
extern int explicitsky;

extern void drawskybox(int farplane);
extern bool limitsky();
extern bool renderexplicitsky(bool outline = false);

// 3dgui
extern void g3d_render();
extern bool g3d_windowhit(bool on, bool act);

// menus
extern int mainmenu;

extern void clearmainmenu();
extern void g3d_mainmenu();

// sound
extern void clearmapsounds();
extern void checkmapsounds();
extern void updatesounds();

extern void initmumble();
extern void closemumble();
extern void updatemumble();

// grass
extern void generategrass();
extern void rendergrass();

// blendmap
extern int blendpaintmode;

struct BlendMapCache;
extern BlendMapCache *newblendmapcache();
extern void freeblendmapcache(BlendMapCache *&cache);
extern bool setblendmaporigin(BlendMapCache *cache, const ivec &o, int size);
extern bool hasblendmap(BlendMapCache *cache);
extern uchar lookupblendmap(BlendMapCache *cache, const vec &pos);
extern void resetblendmap();
extern void enlargeblendmap();
extern void shrinkblendmap(int octant);
extern void optimizeblendmap();
extern void stoppaintblendmap();
extern void trypaintblendmap();
extern void renderblendbrush(GLuint tex, float x, float y, float w, float h);
extern void renderblendbrush();
extern bool loadblendmap(stream *f, int info);
extern void saveblendmap(stream *f);
extern uchar shouldsaveblendmap();
extern bool usesblendmap(int x1 = 0, int y1 = 0, int x2 = worldsize, int y2 = worldsize);
extern int calcblendlayer(int x1, int y1, int x2, int y2);
extern void updateblendtextures(int x1 = 0, int y1 = 0, int x2 = worldsize, int y2 = worldsize);
extern void bindblendtexture(const ivec &p);
extern void clearblendtextures();

// recorder

namespace recorder
{
    extern void stop();
    extern void capture();
    extern void cleanup();
}

#endif

#endif

