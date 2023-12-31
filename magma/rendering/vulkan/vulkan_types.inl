#pragma once

#include "base.h"
#include "../rhi_renderer.h"

#include <volk.h>

typedef struct mg_vulkan_sampler mg_vulkan_sampler_t;
struct mg_vulkan_sampler
{
    VkSamplerAddressMode address_mode;
    VkFilter filter;
    VkSampler sampler;
};

typedef struct mg_vulkan_image mg_vulkan_image_t;
struct mg_vulkan_image
{
    VkImage image;
    VkImageView view;
    VkDeviceMemory memory;
    VkDescriptorSet descriptor_set;
};

typedef struct mg_vulkan_buffer mg_vulkan_buffer_t,
    mg_vulkan_vertex_buffer_t, mg_vulkan_index_buffer_t;
struct mg_vulkan_buffer
{
    VkBuffer buffer;
    VkDeviceMemory memory;

    VkBuffer staging_buffer;
    VkDeviceMemory staging_memory;
};

typedef struct mg_vulkan_dynamic_buffer mg_vulkan_dynamic_buffer_t,
    mg_vulkan_dynamic_vertex_buffer_t, mg_vulkan_dynamic_index_buffer_t;
struct mg_vulkan_dynamic_buffer
{
    VkBuffer buffer;
    VkDeviceMemory memory;

    void *data;
};

typedef struct mg_vulkan_uniform_buffer mg_vulkan_uniform_buffer_t;
struct mg_vulkan_uniform_buffer
{
    VkBuffer buffer;
    VkDeviceMemory memory;

    VkDescriptorSet descriptor_set;

    void *data;
};

typedef struct mg_vulkan_pipeline mg_vulkan_pipeline_t;
struct mg_vulkan_pipeline
{
	VkPipelineLayout pipeline_layout;
    VkPipeline pipeline;
};

typedef struct mg_vulkan_context mg_vulkan_context_t;
struct mg_vulkan_context
{
    VkInstance instance;
    VkSurfaceKHR surface;

    struct
    {
        VkPhysicalDevice handle;
        uint32_t graphics_family;
        VkPhysicalDeviceProperties properties;
        VkPhysicalDeviceFeatures features;
    }
    physical_device;

    struct
    {
        VkDevice handle;
        VkQueue graphics_queue;
    }
    device;

    struct
    {
        VkSwapchainKHR handle;

        VkImage *images;
        VkImageView *image_views;
        VkFramebuffer *framebuffers;

        uint32_t image_count;
    }
    swapchain;

    struct
    {
        VkFence fence;
        VkSemaphore image_available_semaphore;
        VkSemaphore image_rendered_semaphore;
    }
    sync_objects;

    VkRenderPass render_pass;

    VkCommandPool command_pool;
    VkCommandBuffer command_buffer;
    VkDescriptorPool descriptor_pool;

    struct
    {
        VkDescriptorSetLayout uniform_buffer_layout;
        VkDescriptorSetLayout image_sampler_layout;
    }
    layouts;

    int32_t image_index;
};