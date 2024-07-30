//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//  all external data is defined here
//  most of the data is loaded into different structures at run time
//  some internal structures shared by many modules are here
//

#ifndef __DOOMDATA__
#define __DOOMDATA__

// The most basic types we use, portability.
#include "doomtype.h"

// Some global defines, that configure the game.
#include "doomdef.h"



//
// Map level types.
// The following data structures define the persistent format
// used in the lumps of the WAD files.
//

// Lump order in a map WAD: each map needs a couple of lumps
// to provide a complete scene geometry description.
enum
{
  ML_LABEL,                // A separator, name, ExMx or MAPxx
  ML_THINGS,                // Monsters, items..
  ML_LINEDEFS,                // LineDefs, from editing
  ML_SIDEDEFS,                // SideDefs, from editing
  ML_VERTEXES,                // Vertices, edited and BSP splits generated
  ML_SEGS,                // LineSegs, from LineDefs split by BSP
  ML_SSECTORS,                // SubSectors, list of LineSegs
  ML_NODES,                // BSP nodes
  ML_SECTORS,                // Sectors, from editing
  ML_REJECT,                // LUT, sector-sector visibility
  ML_BLOCKMAP                // LUT, motion clipping, walls/grid element
};


// A single Vertex.
typedef struct
{
  int                x;
  int                y;
} PACKEDATTR mapvertex_t;


// A SideDef, defining the visual appearance of a wall,
// by setting textures and offsets.
typedef struct
{
  int                textureoffset;
  int                rowoffset;
  int                toptexture[8];
  int                bottomtexture[8];
  int                midtexture[8];
  // Front sector, towards viewer.
  int                sector;
} PACKEDATTR mapsidedef_t;



// A LineDef, as used for editing, and as input
// to the BSP builder.
typedef struct
{
  int                v1;
  int                v2;
  int                flags;
  int                special;
  int                tag;
  // sidenum[1] will be -1 if one sided
  int                sidenum[2];
} PACKEDATTR maplinedef_t;


//
// LineDef attributes.
//

// Solid, is an obstacle.
#define ML_BLOCKING                1

// Blocks monsters only.
#define ML_BLOCKMONSTERS        2

// Backside will not be present at all
//  if not two sided.
#define ML_TWOSIDED                4

// If a texture is pegged, the texture will have
// the end exposed to air held constant at the
// top or bottom of the texture (stairs or pulled
// down things) and will move with a height change
// of one of the neighbor sectors.
// Unpegged textures allways have the first row of
// the texture at the top pixel of the line for both
// top and bottom textures (use next to windows).

// upper texture unpegged
#define ML_DONTPEGTOP                8

// lower texture unpegged
#define ML_DONTPEGBOTTOM        16

// In AutoMap: don't map as two sided: IT'S A SECRET!
#define ML_SECRET                32

// Sound rendering: don't let sound cross two of these.
#define ML_SOUNDBLOCK                64

// Don't draw on the automap at all.
#define ML_DONTDRAW                128

// Set if already seen, thus drawn in automap.
#define ML_MAPPED                256




// Sector definition, from editing.
typedef        struct
{
  int                floorheight;
  int                ceilingheight;
  int                floorpic[8];
  int                ceilingpic[8];
  int                lightlevel;
  int                special;
  int                tag;
} PACKEDATTR mapsector_t;

// SubSector, as generated by BSP.
typedef struct
{
  int                numsegs;
  // Index of first one, segs are stored sequentially.
  int                firstseg;
} PACKEDATTR mapsubsector_t;


// LineSeg, generated by splitting LineDefs
// using partition lines selected by BSP builder.
typedef struct
{
  int                v1;
  int                v2;
  int                angle;
  int                linedef;
  int                side;
  int                offset;
} PACKEDATTR mapseg_t;



// BSP node structure.

// Indicate a leaf.
#define        NF_SUBSECTOR        0x8000

typedef struct
{
  // Partition line from (x,y) to x+dx,y+dy)
  int                x;
  int                y;
  int                dx;
  int                dy;

  // Bounding box for each child,
  // clip against view frustum.
  int                bbox[2][4];

  // If NF_SUBSECTOR its a subsector,
  // else it's a node of another subtree.
  unsigned int        children[2];

} PACKEDATTR mapnode_t;




// Thing definition, position, orientation and type,
// plus skill/visibility flags and attributes.
typedef struct
{
    int                x;
    int                y;
    int                angle;
    int                type;
    int                options;
} PACKEDATTR mapthing_t;





#endif                        // __DOOMDATA__
