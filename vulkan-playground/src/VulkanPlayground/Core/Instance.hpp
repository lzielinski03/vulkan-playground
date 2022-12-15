#pragma once
#include "VulkanPlayground/Core.hpp"
#include <vulkan/vulkan_core.h>
#include <vector>

namespace VulkanPG {

	class VPL_API Instance {
	public:
		Instance();
		~Instance();

		void initVulkan();
	private:
		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;

		std::vector<const char*> getRequiredExtensions();
		bool checkValidationLayerSupport();
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		void setupDebugMessenger();

	};
}