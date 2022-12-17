#pragma once
#include "VulkanPlayground/Core.hpp"
#include <vulkan/vulkan_core.h>
#include <vector>
#include <optional>

namespace VulkanPG {

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;

		bool isComplete() {
			return graphicsFamily.has_value();
		}
	};

	class VPL_API Instance {
	public:
		Instance();
		~Instance();

		void initVulkan();
	private:
		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;

		VkDevice device;
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

		VkQueue graphicsQueue;

		void createInstance();
		void setupDebugMessenger();
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		bool checkValidationLayerSupport();
		std::vector<const char*> getRequiredExtensions();

		void pickPhysicalDevice();
		bool Instance::isDeviceSuitable(VkPhysicalDevice device);

		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		void createLogicalDevice();
	};
}