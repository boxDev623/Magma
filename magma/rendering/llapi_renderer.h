#pragma once

#include "platform/platform.h"

#include "math/vec2.h"
#include "math/vec4.h"

typedef void *mg_handle_t;

typedef enum mg_renderer_type mg_renderer_type_t;
enum mg_renderer_type
{
    MG_RENDERER_TYPE_OPENGL,
    MG_RENDERER_TYPE_VULKAN
};

typedef enum mg_buffer_usage mg_buffer_usage_t;
enum mg_buffer_usage
{
    MG_BUFFER_USAGE_UNIFORM = 0x00000010,
    MG_BUFFER_USAGE_STORAGE = 0x00000020,
    MG_BUFFER_USAGE_INDEX = 0x00000040,
    MG_BUFFER_USAGE_VERTEX = 0x00000080
};

typedef enum mg_index_type mg_index_type_t;
enum mg_index_type
{
    MG_INDEX_TYPE_UINT16 = 0,
    MG_INDEX_TYPE_UINT32 = 1
};

typedef enum mg_buffer_update_frequency mg_buffer_update_frequency_t;
enum mg_buffer_update_frequency
{
    MG_BUFFER_UPDATE_FREQUENCY_STATIC,
    MG_BUFFER_UPDATE_FREQUENCY_DYNAMIC
};

typedef struct mg_buffer_create_info mg_buffer_create_info_t;
struct mg_buffer_create_info
{
    mg_buffer_usage_t usage;
    mg_buffer_update_frequency_t frequency;
    
    size_t size;

    bool mapped_at_creation;
};

typedef struct mg_buffer_update_info mg_buffer_update_info_t;
struct mg_buffer_update_info
{
    size_t size;
    void *data;
};

typedef struct mg_buffer mg_buffer_t;
struct mg_buffer
{
    mg_handle_t internal_data;
};

typedef enum mg_pixel_format mg_pixel_format_t;
enum mg_pixel_format
{
    MG_PIXEL_FORMAT_R8_UNORM = 9,
    MG_PIXEL_FORMAT_R8_SNORM = 10,
    MG_PIXEL_FORMAT_R8_USCALED = 11,
    MG_PIXEL_FORMAT_R8_SSCALED = 12,
    MG_PIXEL_FORMAT_R8_UINT = 13,
    MG_PIXEL_FORMAT_R8_SINT = 14,
    MG_PIXEL_FORMAT_R8_SRGB = 15,
    MG_PIXEL_FORMAT_R8G8_UNORM = 16,
    MG_PIXEL_FORMAT_R8G8_SNORM = 17,
    MG_PIXEL_FORMAT_R8G8_USCALED = 18,
    MG_PIXEL_FORMAT_R8G8_SSCALED = 19,
    MG_PIXEL_FORMAT_R8G8_UINT = 20,
    MG_PIXEL_FORMAT_R8G8_SINT = 21,
    MG_PIXEL_FORMAT_R8G8_SRGB = 22,
    MG_PIXEL_FORMAT_R8G8B8_UNORM = 23,
    MG_PIXEL_FORMAT_R8G8B8_SNORM = 24,
    MG_PIXEL_FORMAT_R8G8B8_USCALED = 25,
    MG_PIXEL_FORMAT_R8G8B8_SSCALED = 26,
    MG_PIXEL_FORMAT_R8G8B8_UINT = 27,
    MG_PIXEL_FORMAT_R8G8B8_SINT = 28,
    MG_PIXEL_FORMAT_R8G8B8_SRGB = 29,
    MG_PIXEL_FORMAT_B8G8R8_UNORM = 30,
    MG_PIXEL_FORMAT_B8G8R8_SNORM = 31,
    MG_PIXEL_FORMAT_B8G8R8_USCALED = 32,
    MG_PIXEL_FORMAT_B8G8R8_SSCALED = 33,
    MG_PIXEL_FORMAT_B8G8R8_UINT = 34,
    MG_PIXEL_FORMAT_B8G8R8_SINT = 35,
    MG_PIXEL_FORMAT_B8G8R8_SRGB = 36,
    MG_PIXEL_FORMAT_R8G8B8A8_UNORM = 37,
    MG_PIXEL_FORMAT_R8G8B8A8_SNORM = 38,
    MG_PIXEL_FORMAT_R8G8B8A8_USCALED = 39,
    MG_PIXEL_FORMAT_R8G8B8A8_SSCALED = 40,
    MG_PIXEL_FORMAT_R8G8B8A8_UINT = 41,
    MG_PIXEL_FORMAT_R8G8B8A8_SINT = 42,
    MG_PIXEL_FORMAT_R8G8B8A8_SRGB = 43,
    MG_PIXEL_FORMAT_B8G8R8A8_UNORM = 44,
    MG_PIXEL_FORMAT_B8G8R8A8_SNORM = 45,
    MG_PIXEL_FORMAT_B8G8R8A8_USCALED = 46,
    MG_PIXEL_FORMAT_B8G8R8A8_SSCALED = 47,
    MG_PIXEL_FORMAT_B8G8R8A8_UINT = 48,
    MG_PIXEL_FORMAT_B8G8R8A8_SINT = 49,
    MG_PIXEL_FORMAT_B8G8R8A8_SRGB = 50,
    MG_PIXEL_FORMAT_R16_UNORM = 70,
    MG_PIXEL_FORMAT_R16_SNORM = 71,
    MG_PIXEL_FORMAT_R16_USCALED = 72,
    MG_PIXEL_FORMAT_R16_SSCALED = 73,
    MG_PIXEL_FORMAT_R16_UINT = 74,
    MG_PIXEL_FORMAT_R16_SINT = 75,
    MG_PIXEL_FORMAT_R16_SFLOAT = 76,
    MG_PIXEL_FORMAT_R16G16_UNORM = 77,
    MG_PIXEL_FORMAT_R16G16_SNORM = 78,
    MG_PIXEL_FORMAT_R16G16_USCALED = 79,
    MG_PIXEL_FORMAT_R16G16_SSCALED = 80,
    MG_PIXEL_FORMAT_R16G16_UINT = 81,
    MG_PIXEL_FORMAT_R16G16_SINT = 82,
    MG_PIXEL_FORMAT_R16G16_SFLOAT = 83,
    MG_PIXEL_FORMAT_R16G16B16_UNORM = 84,
    MG_PIXEL_FORMAT_R16G16B16_SNORM = 85,
    MG_PIXEL_FORMAT_R16G16B16_USCALED = 86,
    MG_PIXEL_FORMAT_R16G16B16_SSCALED = 87,
    MG_PIXEL_FORMAT_R16G16B16_UINT = 88,
    MG_PIXEL_FORMAT_R16G16B16_SINT = 89,
    MG_PIXEL_FORMAT_R16G16B16_SFLOAT = 90,
    MG_PIXEL_FORMAT_R16G16B16A16_UNORM = 91,
    MG_PIXEL_FORMAT_R16G16B16A16_SNORM = 92,
    MG_PIXEL_FORMAT_R16G16B16A16_USCALED = 93,
    MG_PIXEL_FORMAT_R16G16B16A16_SSCALED = 94,
    MG_PIXEL_FORMAT_R16G16B16A16_UINT = 95,
    MG_PIXEL_FORMAT_R16G16B16A16_SINT = 96,
    MG_PIXEL_FORMAT_R16G16B16A16_SFLOAT = 97,
    MG_PIXEL_FORMAT_R32_UINT = 98,
    MG_PIXEL_FORMAT_R32_SINT = 99,
    MG_PIXEL_FORMAT_R32_SFLOAT = 100,
    MG_PIXEL_FORMAT_R32G32_UINT = 101,
    MG_PIXEL_FORMAT_R32G32_SINT = 102,
    MG_PIXEL_FORMAT_R32G32_SFLOAT = 103,
    MG_PIXEL_FORMAT_R32G32B32_UINT = 104,
    MG_PIXEL_FORMAT_R32G32B32_SINT = 105,
    MG_PIXEL_FORMAT_R32G32B32_SFLOAT = 106,
    MG_PIXEL_FORMAT_R32G32B32A32_UINT = 107,
    MG_PIXEL_FORMAT_R32G32B32A32_SINT = 108,
    MG_PIXEL_FORMAT_R32G32B32A32_SFLOAT = 109,
    MG_PIXEL_FORMAT_R64_UINT = 110,
    MG_PIXEL_FORMAT_R64_SINT = 111,
    MG_PIXEL_FORMAT_R64_SFLOAT = 112,
    MG_PIXEL_FORMAT_R64G64_UINT = 113,
    MG_PIXEL_FORMAT_R64G64_SINT = 114,
    MG_PIXEL_FORMAT_R64G64_SFLOAT = 115,
    MG_PIXEL_FORMAT_R64G64B64_UINT = 116,
    MG_PIXEL_FORMAT_R64G64B64_SINT = 117,
    MG_PIXEL_FORMAT_R64G64B64_SFLOAT = 118,
    MG_PIXEL_FORMAT_R64G64B64A64_UINT = 119,
    MG_PIXEL_FORMAT_R64G64B64A64_SINT = 120,
    MG_PIXEL_FORMAT_R64G64B64A64_SFLOAT = 121
};

typedef struct mg_texture_image_create_info mg_texture_image_create_info_t;
struct mg_texture_image_create_info
{
    mg_vec2i_t extent;
};

typedef struct mg_texture_image mg_texture_image_t;
struct mg_texture_image
{
    mg_handle_t internal_data;
};

typedef struct mg_texture_image_write_info mg_texture_image_write_info_t;
struct mg_texture_image_write_info
{
    mg_vec2i_t extent;
    void *data;
};

typedef struct mg_texture_view mg_texture_view_t;
struct mg_texture_view
{
    mg_handle_t internal_data;
};

typedef enum mg_sampler_filter mg_sampler_filter_t;
enum mg_sampler_filter
{
    MG_SAMPLER_FILTER_NEAREST = 0,
    MG_SAMPLER_FILTER_LINEAR = 1
};

typedef enum mg_sampler_address_mode mg_sampler_address_mode_t;
enum mg_sampler_address_mode
{
    MG_SAMPLER_ADDRESS_MODE_REPEAT = 0,
    MG_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT = 1,
    MG_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE = 2,
    MG_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER = 3,
    MG_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE = 4
};

typedef struct mg_sampler_create_info mg_sampler_create_info_t;
struct mg_sampler_create_info
{
    mg_sampler_filter_t mag_filter;
    mg_sampler_filter_t min_filter;

    mg_sampler_address_mode_t address_mode_u;
    mg_sampler_address_mode_t address_mode_v;
    mg_sampler_address_mode_t address_mode_w;
};

typedef struct mg_sampler mg_sampler_t;
struct mg_sampler
{
    mg_handle_t internal_data;
};

typedef struct mg_render_pass mg_render_pass_t;
struct mg_render_pass
{
    mg_handle_t internal_data;
};

typedef struct mg_framebuffer_create_info mg_framebuffer_create_info_t;
struct mg_framebuffer_create_info
{
    mg_texture_view_t texture_view;
    mg_render_pass_t render_pass;
    mg_vec2i_t extent;
};

typedef struct mg_framebuffer mg_framebuffer_t;
struct mg_framebuffer
{
    mg_handle_t internal_data;
};

typedef struct mg_render_pass_begin_info mg_render_pass_begin_info_t;
struct mg_render_pass_begin_info
{
    mg_framebuffer_t framebuffer;
    mg_vec4_t render_area;
    mg_vec4_t clear_value;
};

typedef enum mg_primitive_topology mg_primitive_topology_t;
enum mg_primitive_topology
{
    MG_PRIMITIVE_TOPOLOGY_POINT_LIST = 0,
    MG_PRIMITIVE_TOPOLOGY_LINE_LIST = 1,
    MG_PRIMITIVE_TOPOLOGY_LINE_STRIP = 2,
    MG_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST = 3,
    MG_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 4
};

typedef enum mg_polygon_mode mg_polygon_mode_t;
enum mg_polygon_mode
{
    MG_POLYGON_MODE_FILL = 0,
    MG_POLYGON_MODE_LINE = 1,
    MG_POLYGON_MODE_POINT = 2
};

typedef enum mg_cull_mode mg_cull_mode_t;
enum mg_cull_mode
{
    MG_CULL_MODE_NONE = 0,
    MG_CULL_MODE_FRONT = 0x00000001,
    MG_CULL_MODE_BACK = 0x00000002,
    MG_CULL_MODE_FRONT_AND_BACK = 0x00000003
};

typedef enum mg_front_face mg_front_face_t;
enum mg_front_face
{
    MG_FRONT_FACE_CCW = 0,
    MG_FRONT_FACE_CW = 1
};

typedef enum mg_blend_factor mg_blend_factor_t;
enum mg_blend_factor
{
    MG_BLEND_FACTOR_ZERO = 0,
    MG_BLEND_FACTOR_ONE = 1,
    MG_BLEND_FACTOR_SRC_COLOR = 2,
    MG_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3,
    MG_BLEND_FACTOR_DST_COLOR = 4,
    MG_BLEND_FACTOR_ONE_MINUS_DST_COLOR = 5,
    MG_BLEND_FACTOR_SRC_ALPHA = 6,
    MG_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 7,
    MG_BLEND_FACTOR_DST_ALPHA = 8,
    MG_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 9,
    MG_BLEND_FACTOR_CONSTANT_COLOR = 10,
    MG_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11,
    MG_BLEND_FACTOR_CONSTANT_ALPHA = 12,
    MG_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 13,
    MG_BLEND_FACTOR_SRC_ALPHA_SATURATE = 14,
    MG_BLEND_FACTOR_SRC1_COLOR = 15,
    MG_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR = 16,
    MG_BLEND_FACTOR_SRC1_ALPHA = 17,
    MG_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA = 18
};

typedef enum mg_blend_op mg_blend_op_t;
enum mg_blend_op
{
    MG_BLEND_OP_ADD = 0,
    MG_BLEND_OP_SUBTRACT = 1,
    MG_BLEND_OP_REVERSE_SUBTRACT = 2,
    MG_BLEND_OP_MIN = 3,
    MG_BLEND_OP_MAX = 4,
    MG_BLEND_OP_ZERO = 1000148000,
    MG_BLEND_OP_SRC = 1000148001,
    MG_BLEND_OP_DST = 1000148002,
    MG_BLEND_OP_SRC_OVER = 1000148003,
    MG_BLEND_OP_DST_OVER = 1000148004,
    MG_BLEND_OP_SRC_IN = 1000148005,
    MG_BLEND_OP_DST_IN = 1000148006,
    MG_BLEND_OP_SRC_OUT = 1000148007,
    MG_BLEND_OP_DST_OUT = 1000148008,
    MG_BLEND_OP_SRC_ATOP = 1000148009,
    MG_BLEND_OP_DST_ATOP = 1000148010,
    MG_BLEND_OP_XOR = 1000148011,
    MG_BLEND_OP_MULTIPLY = 1000148012,
    MG_BLEND_OP_SCREEN = 1000148013,
    MG_BLEND_OP_OVERLAY = 1000148014,
    MG_BLEND_OP_DARKEN = 1000148015,
    MG_BLEND_OP_LIGHTEN = 1000148016,
    MG_BLEND_OP_COLORDODGE = 1000148017,
    MG_BLEND_OP_COLORBURN = 1000148018,
    MG_BLEND_OP_HARDLIGHT = 1000148019,
    MG_BLEND_OP_SOFTLIGHT = 1000148020,
    MG_BLEND_OP_DIFFERENCE = 1000148021,
    MG_BLEND_OP_EXCLUSION = 1000148022,
    MG_BLEND_OP_INVERT = 1000148023,
    MG_BLEND_OP_INVERT_RGB = 1000148024,
    MG_BLEND_OP_LINEARDODGE = 1000148025,
    MG_BLEND_OP_LINEARBURN = 1000148026,
    MG_BLEND_OP_VIVIDLIGHT = 1000148027,
    MG_BLEND_OP_LINEARLIGHT = 1000148028,
    MG_BLEND_OP_PINLIGHT = 1000148029,
    MG_BLEND_OP_HARDMIX = 1000148030,
    MG_BLEND_OP_HSL_HUE = 1000148031,
    MG_BLEND_OP_HSL_SATURATION = 1000148032,
    MG_BLEND_OP_HSL_COLOR = 1000148033,
    MG_BLEND_OP_HSL_LUMINOSITY = 1000148034,
    MG_BLEND_OP_PLUS = 1000148035,
    MG_BLEND_OP_PLUS_CLAMPED = 1000148036,
    MG_BLEND_OP_PLUS_CLAMPED_ALPHA = 1000148037,
    MG_BLEND_OP_PLUS_DARKER = 1000148038,
    MG_BLEND_OP_MINUS = 1000148039,
    MG_BLEND_OP_MINUS_CLAMPED = 1000148040,
    MG_BLEND_OP_CONTRAST = 1000148041,
    MG_BLEND_OP_INVERT_OVG = 1000148042,
    MG_BLEND_OP_RED = 1000148043,
    MG_BLEND_OP_GREEN = 1000148044,
    MG_BLEND_OP_BLUE = 1000148045
};

typedef struct mg_color_blend mg_color_blend_t;
struct mg_color_blend
{
    bool blend_enabled;

    mg_blend_factor_t src_color_blend_factor;
    mg_blend_factor_t dst_color_blend_factor;
    mg_blend_op_t color_blend_op;
    
    mg_blend_factor_t src_alpha_blend_factor;
    mg_blend_factor_t dst_alpha_blend_factor;
    mg_blend_op_t alpha_blend_op;
};

typedef enum mg_shader_stage mg_shader_stage_t;
enum mg_shader_stage
{
    MG_SHADER_STAGE_VERTEX = 0x00000001,
    MG_SHADER_STAGE_GEOMETRY = 0x00000008,
    MG_SHADER_STAGE_FRAGMENT = 0x00000010,
    MG_SHADER_STAGE_COMPUTE = 0x00000020
};

typedef enum mg_descriptor_type mg_descriptor_type_t;
enum mg_descriptor_type
{
    MG_DESCRIPTOR_TYPE_SAMPLER = 0,
    MG_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = 1,
    MG_DESCRIPTOR_TYPE_SAMPLED_IMAGE = 2,
    MG_DESCRIPTOR_TYPE_STORAGE_IMAGE = 3,
    MG_DESCRIPTOR_TYPE_UNIFORM_BUFFER = 6,
    MG_DESCRIPTOR_TYPE_STORAGE_BUFFER = 7
};
 
typedef struct mg_descriptor mg_descriptor_t;
struct mg_descriptor
{
    mg_descriptor_type_t type;
    mg_shader_stage_t stage;
    uint32_t binding;
};

typedef struct mg_descriptor_set_layout_create_info mg_descriptor_set_layout_create_info_t;
struct mg_descriptor_set_layout_create_info
{
    mg_descriptor_t *descriptors;
    uint32_t descriptor_count;
};

typedef struct mg_descriptor_set_layout mg_descriptor_set_layout_t;
struct mg_descriptor_set_layout
{
    mg_handle_t internal_data;
};

typedef struct mg_descriptor_set_create_info mg_descriptor_set_create_info_t;
struct mg_descriptor_set_create_info
{
    mg_descriptor_set_layout_t *layouts;
};

typedef struct mg_descriptor_set mg_descriptor_set_t;
struct mg_descriptor_set
{
    mg_handle_t internal_data;
};

typedef struct mg_descriptor_buffer_info mg_descriptor_buffer_info_t;
struct mg_descriptor_buffer_info
{
    mg_buffer_t buffer;
    size_t offset;
    size_t range;
};

typedef struct mg_descriptor_image_info mg_descriptor_image_info_t;
struct mg_descriptor_image_info
{
    mg_sampler_t sampler;
    mg_texture_view_t view;
};

typedef struct mg_descriptor_write mg_descriptor_write_t;
struct mg_descriptor_write
{
    uint32_t binding;
    mg_descriptor_type_t descriptor_type;
    mg_descriptor_buffer_info_t *buffer_info;
    mg_descriptor_image_info_t *image_info;
};

typedef enum mg_vertex_format mg_vertex_format_t;
enum mg_vertex_format
{
    MG_VERTEX_FORMAT_UINT = 98,
    MG_VERTEX_FORMAT_INT = 99,
    MG_VERTEX_FORMAT_FLOAT = 100,

    MG_VERTEX_FORMAT_UINT2 = 101,
    MG_VERTEX_FORMAT_INT2 = 102,
    MG_VERTEX_FORMAT_FLOAT2 = 103,

    MG_VERTEX_FORMAT_UINT3 = 104,
    MG_VERTEX_FORMAT_INT3 = 105,
    MG_VERTEX_FORMAT_FLOAT3 = 106,

    MG_VERTEX_FORMAT_UINT4 = 107,
    MG_VERTEX_FORMAT_INT4 = 108,
    MG_VERTEX_FORMAT_FLOAT4 = 109
};

typedef struct mg_vertex_attribute_info mg_vertex_attribute_info_t;
struct mg_vertex_attribute_info
{
    uint32_t location;
    mg_vertex_format_t format;
    uint32_t offset;
};

typedef struct mg_vertex_layout_info mg_vertex_layout_info_t;
struct mg_vertex_layout_info
{
    uint32_t stride;
    mg_vertex_attribute_info_t *attributes;
    uint32_t attribute_count;
};

/*typedef enum mg_shader_type mg_shader_type_t;
enum mg_shader_type
{
	MG_SHADER_TYPE_VERTEX = 0x00000001,
	MG_SHADER_TYPE_GEOMETRY = 0x00000008,
	MG_SHADER_TYPE_FRAGMENT = 0x00000010,
	MG_SHADER_TYPE_COMPUTE = 0x00000020
};*/

typedef struct mg_shader_source mg_shader_source_t;
struct mg_shader_source
{
	uint32_t* code;
	size_t code_size;
};

typedef struct mg_program_create_info mg_program_create_info_t;
struct mg_program_create_info
{
    mg_shader_source_t *vertex_shader;
    mg_shader_source_t *fragment_shader;

    mg_vertex_layout_info_t vertex_layout;

    mg_primitive_topology_t primitive_topology;
    mg_polygon_mode_t polygon_mode;
    mg_cull_mode_t cull_mode;
    mg_front_face_t front_face;
    mg_color_blend_t color_blend;
    
    mg_descriptor_set_layout_t *desctriptor_set_layouts;
    uint32_t desctriptor_set_layout_count;

    mg_render_pass_t render_pass;

    bool has_push_constants;
    uint16_t push_constants_size;
};

typedef struct mg_program mg_program_t;
struct mg_program
{
    mg_handle_t internal_data;
};

typedef enum mg_present_mode mg_present_mode_t;
enum mg_present_mode
{
    MG_PRESENT_MODE_IMMEDIATE_KHR = 0,
    MG_PRESENT_MODE_MAILBOX_KHR = 1,
    MG_PRESENT_MODE_FIFO_KHR = 2,
    MG_PRESENT_MODE_FIFO_RELAXED_KHR = 3
};

typedef struct mg_swapchain_config_info mg_swapchain_config_info_t;
struct mg_swapchain_config_info
{
    mg_vec2i_t extent;
    mg_pixel_format_t format;
    mg_present_mode_t present_mode;
};

typedef struct mg_renderer_init_info mg_renderer_init_info_t;
struct mg_renderer_init_info
{
    mg_platform_t *platform;
    mg_renderer_type_t type;
    mg_swapchain_config_info_t *swapchain_config_info;
};

MG_API void mg_llapi_renderer_initialize    (mg_renderer_init_info_t *init_info);
MG_API void mg_llapi_renderer_shutdown      (void);

MG_API void mg_llapi_renderer_begin_frame   (void);
MG_API void mg_llapi_renderer_end_frame     (void);

MG_API void mg_llapi_renderer_present_frame (void);

MG_API void mg_llapi_renderer_wait          (void);

MG_API void mg_llapi_renderer_viewport      (uint32_t width, uint32_t height);

MG_API void mg_llapi_renderer_draw          (uint32_t vertex_count, uint32_t first_vertex);
MG_API void mg_llapi_renderer_draw_indexed  (uint32_t index_count, uint32_t first_index);

MG_API void                 mg_llapi_renderer_configure_swapchain       (mg_swapchain_config_info_t *config_info);
MG_API mg_framebuffer_t     mg_llapi_renderer_get_swapchain_framebuffer (void);

MG_API mg_render_pass_t mg_llapi_renderer_create_render_pass    (void);
MG_API void             mg_llapi_renderer_destroy_render_pass   (mg_render_pass_t render_pass);
MG_API void             mg_llapi_renderer_begin_render_pass     (mg_render_pass_t render_pass, mg_render_pass_begin_info_t *begin_info);
MG_API void             mg_llapi_renderer_end_render_pass       (void);

MG_API mg_descriptor_set_layout_t   mg_llapi_renderer_create_descriptor_set_layout  (mg_descriptor_set_layout_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_destroy_descriptor_set_layout (mg_descriptor_set_layout_t descriptor_set_layout);

MG_API mg_descriptor_set_t          mg_llapi_renderer_create_descriptor_set         (mg_descriptor_set_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_update_descriptor_set         (mg_descriptor_set_t descriptor_set, mg_descriptor_write_t *descriptor_write);
MG_API void                         mg_llapi_renderer_destroy_descriptor_set        (mg_descriptor_set_t descriptor_set);
MG_API void                         mg_llapi_renderer_bind_descriptor_set           (mg_descriptor_set_t descriptor_set, mg_program_t program, uint32_t set_index);

MG_API mg_program_t                 mg_llapi_renderer_create_program                (mg_program_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_destroy_program               (mg_program_t program);
MG_API void                         mg_llapi_renderer_bind_program                  (mg_program_t program);

MG_API mg_buffer_t                  mg_llapi_renderer_create_buffer                 (mg_buffer_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_update_buffer                 (mg_buffer_t buffer, mg_buffer_update_info_t *update_info);
MG_API void                         mg_llapi_renderer_destroy_buffer                (mg_buffer_t buffer);

MG_API mg_texture_image_t           mg_llapi_renderer_create_texture_image          (mg_texture_image_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_write_texture_image           (mg_texture_image_t texture_image, mg_texture_image_write_info_t *write_info);
MG_API void                         mg_llapi_renderer_destroy_texture_image         (mg_texture_image_t texture_image);

MG_API mg_texture_view_t            mg_llapi_renderer_create_texture_view           (mg_texture_image_t texture_image);
MG_API void                         mg_llapi_renderer_destroy_texture_view          (mg_texture_view_t texture_view);

MG_API mg_sampler_t                 mg_llapi_renderer_create_sampler                (mg_sampler_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_destroy_sampler               (mg_sampler_t sampler);

MG_API mg_framebuffer_t             mg_llapi_renderer_create_framebuffer            (mg_framebuffer_create_info_t *create_info);
MG_API void                         mg_llapi_renderer_destroy_framebuffer           (mg_framebuffer_t framebuffer);

MG_API void                         mg_llapi_renderer_bind_vertex_buffer            (mg_buffer_t buffer);
MG_API void                         mg_llapi_renderer_bind_index_buffer             (mg_buffer_t buffer, mg_index_type_t index_type);

MG_API void                         mg_llapi_renderer_push_constants                (mg_program_t program, uint32_t size, void *data);