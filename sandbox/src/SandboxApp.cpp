#include <VulkanPlayground.hpp>

class Sandbox : public VulkanPG::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

VulkanPG::Application* VulkanPG::CreateApplication() {
	return new Sandbox();
}