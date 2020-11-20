#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /Emain /D __INST__=40 /D __EFFEKSEER_BUILD_VERSION16__=1
//    /Fh ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderTexture_PS.h
//    Shader/model_renderer_texture_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 fLightDirection;            // Offset:    0 Size:    16 [unused]
//   float4 fLightColor;                // Offset:   16 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset:   32 Size:    16 [unused]
//   float4 fFlipbookParameter;         // Offset:   48 Size:    16
//   float4 fUVDistortionParameter;     // Offset:   64 Size:    16
//   float4 fBlendTextureParameter;     // Offset:   80 Size:    16
//   float4 fCameraFrontDirection;      // Offset:   96 Size:    16
//   
//   struct
//   {
//       
//       float4 Param;                  // Offset:  112
//       float4 BeginColor;             // Offset:  128
//       float4 EndColor;               // Offset:  144
//
//   } fFalloffParam;                   // Offset:  112 Size:    48
//   float4 fEmissiveScaling;           // Offset:  160 Size:    16
//   float4 fEdgeColor;                 // Offset:  176 Size:    16
//   float4 fEdgeParameter;             // Offset:  192 Size:    16
//   float4 softParticleAndReconstructionParam1;// Offset:  208 Size:    16
//   float4 reconstructionParam2;       // Offset:  224 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_colorSampler                    sampler      NA          NA    0        1
// g_alphaSampler                    sampler      NA          NA    1        1
// g_uvDistortionSampler             sampler      NA          NA    2        1
// g_blendSampler                    sampler      NA          NA    3        1
// g_blendAlphaSampler               sampler      NA          NA    4        1
// g_blendUVDistortionSampler        sampler      NA          NA    5        1
// g_depthSampler                    sampler      NA          NA    6        1
// g_colorTexture                    texture  float4          2d    0        1
// g_alphaTexture                    texture  float4          2d    1        1
// g_uvDistortionTexture             texture  float4          2d    2        1
// g_blendTexture                    texture  float4          2d    3        1
// g_blendAlphaTexture               texture  float4          2d    4        1
// g_blendUVDistortionTexture        texture  float4          2d    5        1
// g_depthTexture                    texture  float4          2d    6        1
// PS_ConstanBuffer                  cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 1   xyz         2     NONE  float   xyz 
// TEXCOORD                 2   xyz         3     NONE  float       
// TEXCOORD                 3   xyz         4     NONE  float       
// COLOR                    0   xyzw        5     NONE  float   xyzw
// TEXCOORD                 4   xyzw        6     NONE  float   xyzw
// TEXCOORD                 5   xyzw        7     NONE  float   xyzw
// TEXCOORD                 6   xyzw        8     NONE  float   xyzw
// TEXCOORD                 7   xy          9     NONE  float   xy  
// TEXCOORD                 8   xyzw       10     NONE  float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[15], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_sampler s4, mode_default
dcl_sampler s5, mode_default
dcl_sampler s6, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_resource_texture2d (float,float,float,float) t4
dcl_resource_texture2d (float,float,float,float) t5
dcl_resource_texture2d (float,float,float,float) t6
dcl_input_ps linear centroid v1.xy
dcl_input_ps linear v2.xyz
dcl_input_ps linear centroid v5.xyzw
dcl_input_ps linear v6.xyzw
dcl_input_ps linear v7.xyzw
dcl_input_ps linear v8.xyzw
dcl_input_ps linear v9.xy
dcl_input_ps linear v10.xyzw
dcl_output o0.xyzw
dcl_temps 7
sample r0.xyzw, v6.zwzz, t2.xyzw, s2
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r0.z, -r0.y, cb0[4].w, cb0[4].z
mad r0.yw, r0.xxxz, cb0[4].xxxx, v1.xxxy
sample r1.xyzw, r0.ywyy, t0.xyzw, s0
mul r1.xyzw, r1.xyzw, v5.xyzw
lt r0.y, l(0.000000), cb0[3].x
if_nz r0.y
  mad r0.yw, r0.xxxz, cb0[4].xxxx, v8.zzzw
  sample r2.xyzw, r0.ywyy, t0.xyzw, s0
  eq r0.y, cb0[3].y, l(1.000000)
  mad r2.xyzw, r2.xyzw, v5.xyzw, -r1.xyzw
  mad r2.xyzw, v9.xxxx, r2.xyzw, r1.xyzw
  movc r1.xyzw, r0.yyyy, r2.xyzw, r1.xyzw
endif 
mad r0.xy, r0.xzxx, cb0[4].xxxx, v6.xyxx
sample r0.xyzw, r0.xyxx, t1.xyzw, s1
mul r0.x, r0.w, r0.x
mul r0.w, r0.x, r1.w
sample r2.xyzw, v7.zwzz, t5.xyzw, s5
mad r2.xy, r2.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r2.z, -r2.y, cb0[4].w, cb0[4].z
mad r2.yw, r2.xxxz, cb0[4].yyyy, v8.xxxy
sample r3.xyzw, r2.ywyy, t3.xyzw, s3
mad r2.xy, r2.xzxx, cb0[4].yyyy, v7.xyxx
sample r2.xyzw, r2.xyxx, t4.xyzw, s4
mul r1.w, r2.w, r2.x
mul r2.x, r1.w, r3.w
mul r2.yzw, r3.xxyz, r2.xxxx
mad r1.w, -r3.w, r1.w, l(1.000000)
mad r4.xyz, r1.wwww, r1.xyzx, r2.yzwy
mad r5.xyz, r2.xxxx, r3.xyzx, r1.xyzx
mad r3.xyz, -r2.xxxx, r3.xyzx, r1.xyzx
eq r6.xyzw, cb0[5].xxxx, l(0.000000, 1.000000, 2.000000, 3.000000)
mul r2.xyz, r1.xyzx, r2.yzwy
movc r1.xyz, r6.wwww, r2.xyzx, r1.xyzx
movc r1.xyz, r6.zzzz, r3.xyzx, r1.xyzx
movc r1.xyz, r6.yyyy, r5.xyzx, r1.xyzx
movc r0.xyz, r6.xxxx, r4.xyzx, r1.xyzx
dp3 r1.x, -cb0[6].xyzx, -cb0[6].xyzx
rsq r1.x, r1.x
mul r1.xyz, r1.xxxx, -cb0[6].xyzx
dp3 r1.w, v2.xyzx, v2.xyzx
rsq r1.w, r1.w
mul r2.xyz, r1.wwww, v2.xyzx
dp3_sat r1.x, r1.xyzx, r2.xyzx
log r1.x, r1.x
mul r1.x, r1.x, cb0[7].z
exp r1.x, r1.x
add r2.xyzw, cb0[8].xyzw, -cb0[9].xyzw
mad r1.xyzw, r1.xxxx, r2.xyzw, cb0[9].xyzw
add r2.xyz, r0.xyzx, r1.xyzx
add r3.xyz, r0.xyzx, -r1.xyzx
eq r4.xyzw, cb0[7].xyyy, l(1.000000, 0.000000, 1.000000, 2.000000)
mul r1.xyz, r0.xyzx, r1.xyzx
movc r1.xyz, r4.wwww, r1.xyzx, r0.xyzx
movc r1.xyz, r4.zzzz, r3.xyzx, r1.xyzx
movc r2.xyz, r4.yyyy, r2.xyzx, r1.xyzx
mul r2.w, r0.w, r1.w
movc r0.xyzw, r4.xxxx, r2.xyzw, r0.xyzw
div r1.yzw, v10.xxyz, v10.wwww
add r1.yz, r1.yyzy, l(0.000000, 1.000000, 1.000000, 0.000000)
mul r2.x, r1.y, l(0.500000)
mad r2.z, -r1.z, l(0.500000), l(1.000000)
sample r2.xyzw, r2.xzxx, t6.xyzw, s6
ne r1.y, cb0[13].x, l(0.000000)
mad r1.x, r2.x, cb0[13].y, cb0[13].z
mad r2.xy, r1.xwxx, cb0[14].wwww, -cb0[14].yyyy
mad r1.xz, -r1.xxwx, cb0[14].zzzz, cb0[14].xxxx
div r1.xz, r2.xxyx, r1.xxzx
add r1.x, -r1.x, r1.z
div_sat r1.x, r1.x, cb0[13].x
mul r1.x, r0.w, r1.x
movc r0.w, r1.y, r1.x, r0.w
max r1.x, v9.y, l(0.000000)
ge r1.x, r1.x, r0.w
discard r1.x
mul r1.xyz, cb0[11].xyzx, cb0[12].yyyy
add r1.w, r0.w, -v9.y
add r1.w, r1.w, -cb0[12].x
round_pi r1.w, r1.w
mad r0.xyz, r0.xyzx, cb0[10].xxxx, -r1.xyzx
mad o0.xyz, r1.wwww, r0.xyzx, r1.xyzx
mov o0.w, r0.w
ret 
// Approximately 85 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67, 183, 136, 
     30, 120,  51, 178, 220,  87, 
     65, 150,  78, 233, 146, 230, 
    249,  82,   1,   0,   0,   0, 
    148,  20,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     52,   6,   0,   0, 104,   7, 
      0,   0, 156,   7,   0,   0, 
     24,  20,   0,   0,  82,  68, 
     69,  70, 248,   5,   0,   0, 
      1,   0,   0,   0,  16,   3, 
      0,   0,  15,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    196,   5,   0,   0, 252,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     11,   2,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  26,   2,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  48,   2, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     63,   2,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  83,   2,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 110,   2, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    125,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 140,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 155,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    177,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   3,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 192,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   4,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 212,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      5,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    239,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   6,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 254,   2,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 103,  95, 
     99, 111, 108, 111, 114,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95,  97, 108, 112, 
    104,  97,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
    117, 118,  68, 105, 115, 116, 
    111, 114, 116, 105, 111, 110, 
     83,  97, 109, 112, 108, 101, 
    114,   0, 103,  95,  98, 108, 
    101, 110, 100,  83,  97, 109, 
    112, 108, 101, 114,   0, 103, 
     95,  98, 108, 101, 110, 100, 
     65, 108, 112, 104,  97,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95,  98, 108, 101, 
    110, 100,  85,  86,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
    100, 101, 112, 116, 104,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95,  99, 111, 108, 
    111, 114,  84, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     97, 108, 112, 104,  97,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95, 117, 118,  68, 
    105, 115, 116, 111, 114, 116, 
    105, 111, 110,  84, 101, 120, 
    116, 117, 114, 101,   0, 103, 
     95,  98, 108, 101, 110, 100, 
     84, 101, 120, 116, 117, 114, 
    101,   0, 103,  95,  98, 108, 
    101, 110, 100,  65, 108, 112, 
    104,  97,  84, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     98, 108, 101, 110, 100,  85, 
     86,  68, 105, 115, 116, 111, 
    114, 116, 105, 111, 110,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95, 100, 101, 112, 
    116, 104,  84, 101, 120, 116, 
    117, 114, 101,   0,  80,  83, 
     95,  67, 111, 110, 115, 116, 
     97, 110,  66, 117, 102, 102, 
    101, 114,   0, 171, 254,   2, 
      0,   0,  13,   0,   0,   0, 
     40,   3,   0,   0, 240,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  96,   4, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 128,   4, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 140,   4, 
      0,   0,  32,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 154,   4, 
      0,   0,  48,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 173,   4, 
      0,   0,  64,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 196,   4, 
      0,   0,  80,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 219,   4, 
      0,   0,  96,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 241,   4, 
      0,   0, 112,   0,   0,   0, 
     48,   0,   0,   0,   2,   0, 
      0,   0,  80,   5,   0,   0, 
      0,   0,   0,   0,  96,   5, 
      0,   0, 160,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 113,   5, 
      0,   0, 176,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 124,   5, 
      0,   0, 192,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 139,   5, 
      0,   0, 208,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 175,   5, 
      0,   0, 224,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 102,  76, 
    105, 103, 104, 116,  68, 105, 
    114, 101,  99, 116, 105, 111, 
    110,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  76, 105, 103, 104, 116, 
     67, 111, 108, 111, 114,   0, 
    102,  76, 105, 103, 104, 116, 
     65, 109,  98, 105, 101, 110, 
    116,   0, 102,  70, 108, 105, 
    112,  98, 111, 111, 107,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0, 102,  85,  86, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0, 102,  66, 108, 101, 
    110, 100,  84, 101, 120, 116, 
    117, 114, 101,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0, 102,  67,  97, 109, 101, 
    114,  97,  70, 114, 111, 110, 
    116,  68, 105, 114, 101,  99, 
    116, 105, 111, 110,   0, 102, 
     70,  97, 108, 108, 111, 102, 
    102,  80,  97, 114,  97, 109, 
      0,  80,  97, 114,  97, 109, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  66, 101, 103, 105, 
    110,  67, 111, 108, 111, 114, 
      0,  69, 110, 100,  67, 111, 
    108, 111, 114,   0, 255,   4, 
      0,   0,   8,   5,   0,   0, 
      0,   0,   0,   0,  24,   5, 
      0,   0,   8,   5,   0,   0, 
     16,   0,   0,   0,  35,   5, 
      0,   0,   8,   5,   0,   0, 
     32,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,  12,   0, 
      0,   0,   3,   0,  44,   5, 
      0,   0, 102,  69, 109, 105, 
    115, 115, 105, 118, 101,  83, 
     99,  97, 108, 105, 110, 103, 
      0, 102,  69, 100, 103, 101, 
     67, 111, 108, 111, 114,   0, 
    102,  69, 100, 103, 101,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0, 115, 111, 102, 
    116,  80,  97, 114, 116, 105, 
     99, 108, 101,  65, 110, 100, 
     82, 101,  99, 111, 110, 115, 
    116, 114, 117,  99, 116, 105, 
    111, 110,  80,  97, 114,  97, 
    109,  49,   0, 114, 101,  99, 
    111, 110, 115, 116, 114, 117, 
     99, 116, 105, 111, 110,  80, 
     97, 114,  97, 109,  50,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171, 171, 171,  73,  83, 
     71,  78,  44,   1,   0,   0, 
     11,   0,   0,   0,   8,   0, 
      0,   0,  16,   1,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  28,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,   3, 
      0,   0,  28,   1,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   7,   7, 
      0,   0,  28,   1,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,  28,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,   7,   0, 
      0,   0,  37,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      5,   0,   0,   0,  15,  15, 
      0,   0,  28,   1,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      6,   0,   0,   0,  15,  15, 
      0,   0,  28,   1,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   0,   0,   0,  15,  15, 
      0,   0,  28,   1,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      8,   0,   0,   0,  15,  15, 
      0,   0,  28,   1,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      9,   0,   0,   0,   3,   3, 
      0,   0,  28,   1,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     10,   0,   0,   0,  15,  15, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  67, 
     79,  76,  79,  82,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171,  83,  72, 
     68,  82, 116,  12,   0,   0, 
     64,   0,   0,   0,  29,   3, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   3,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   4,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   5,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   6,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      1,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   2,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   3,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      4,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   5,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   6,   0,   0,   0, 
     85,  85,   0,   0,  98,  24, 
      0,   3,  50,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      2,   0,   0,   0,  98,  24, 
      0,   3, 242,  16,  16,   0, 
      5,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      6,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      8,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      9,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
     10,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   7,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
    230,  26,  16,   0,   6,   0, 
      0,   0,  70, 126,  16,   0, 
      2,   0,   0,   0,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  12,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     50,   0,   0,  10, 162,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   8,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   6,  20,  16,   0, 
      1,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0, 214,   5, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70,  30,  16,   0,   5,   0, 
      0,   0,  49,   0,   0,   8, 
     34,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  31,   0, 
      4,   3,  26,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10, 162,   0,  16,   0, 
      0,   0,   0,   0,   6,   8, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
    166,  30,  16,   0,   8,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0, 214,   5,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   8, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  30,  16,   0,   5,   0, 
      0,   0,  70,  14,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0,   6,  16,  16,   0, 
      9,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  21,   0,   0,   1, 
     50,   0,   0,  10,  50,   0, 
     16,   0,   0,   0,   0,   0, 
    134,   0,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  70,  16,  16,   0, 
      6,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   1,   0, 
      0,   0,   0,  96,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
    230,  26,  16,   0,   7,   0, 
      0,   0,  70, 126,  16,   0, 
      5,   0,   0,   0,   0,  96, 
     16,   0,   5,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  12,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     50,   0,   0,  10, 162,   0, 
     16,   0,   2,   0,   0,   0, 
      6,   8,  16,   0,   2,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   6,  20,  16,   0, 
      8,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      3,   0,   0,   0, 214,   5, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   3,   0, 
      0,   0,   0,  96,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10,  50,   0,  16,   0, 
      2,   0,   0,   0, 134,   0, 
     16,   0,   2,   0,   0,   0, 
     86, 133,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     70,  16,  16,   0,   7,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,  70, 126, 
     16,   0,   4,   0,   0,   0, 
      0,  96,  16,   0,   4,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 226,   0,  16,   0, 
      2,   0,   0,   0,   6,   9, 
     16,   0,   3,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  10, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   4,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0, 150,   7, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   5,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   3,   0,   0,   0, 
      6,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  24,   0, 
      0,  11, 242,   0,  16,   0, 
      6,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,  64,   0,   0,  64,  64, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0, 150,   7,  16,   0, 
      2,   0,   0,   0,  55,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   6,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0, 166,  10, 
     16,   0,   6,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,  86,   5, 
     16,   0,   6,   0,   0,   0, 
     70,   2,  16,   0,   5,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 114,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   6,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  16,   0, 
      0,  11,  18,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     68,   0,   0,   5,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  70,  18, 
     16,   0,   2,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   2,   0,   0,   0, 
     16,  32,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  47,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   8,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  25,   0,   0,   5, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  70, 142, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      0,   0,   0,   7, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8, 114,   0,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     24,   0,   0,  11, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 133,  32,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,  64,  56,   0,   0,   7, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 242,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   7, 226,   0,  16,   0, 
      1,   0,   0,   0,   6,  25, 
     16,   0,  10,   0,   0,   0, 
    246,  31,  16,   0,  10,   0, 
      0,   0,   0,   0,   0,  10, 
     98,   0,  16,   0,   1,   0, 
      0,   0,  86,   6,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,  50,   0, 
      0,  10,  66,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  69,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0, 134,   0,  16,   0, 
      2,   0,   0,   0,  70, 126, 
     16,   0,   6,   0,   0,   0, 
      0,  96,  16,   0,   6,   0, 
      0,   0,  57,   0,   0,   8, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,  13,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  11,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,  13,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,  13,   0,   0,   0, 
     50,   0,   0,  12,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    198,   0,  16,   0,   1,   0, 
      0,   0, 246, 143,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  86, 133,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     50,   0,   0,  12,  82,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   3,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
    166, 138,  32,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     14,   0,   0,   7,  82,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   1,  16,   0,   2,   0, 
      0,   0,   6,   2,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     14,  32,   0,   8,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,  13,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     52,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26,  16,  16,   0,   9,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  29,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  26,  16, 
     16, 128,  65,   0,   0,   0, 
      9,   0,   0,   0,   0,   0, 
      0,   9, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10, 128,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,  66,   0, 
      0,   5, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,  10,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,   9, 
    114,  32,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,  85,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     10,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};