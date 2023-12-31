#version 450

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inTexCoord;

layout(location = 0) out vec2 fragTexCoord;
layout(location = 1) out vec4 fragColor;

layout(binding = 0) uniform UniformBufferObject {
    mat4 projection;
} ubo;

layout(push_constant) uniform PushConstants {
	mat4 model;
    vec4 color;
    vec4 rect;
} push;

void main() {
    gl_Position = ubo.projection * push.model * vec4(inPosition, 0.0, 1.0);
    fragTexCoord = inTexCoord * push.rect.zw + push.rect.xy;
    fragColor = push.color;
}