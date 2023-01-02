#pragma once
#include "VulkanPlayground/Core.hpp"
#include <vulkan/vulkan_core.h>
#include <vector>
#include <optional>
#include "VulkanPlayground/Window.hpp"

namespace VulkanPG {

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class VPL_API Device {
	public:
		Device();
		~Device();

		void initVulkan();
	private:
		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;

		VkDevice device;
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

		VkQueue graphicsQueue;

		VkSurfaceKHR surface;

		VkQueue presentQueue;

		void createInstance();
		void setupDebugMessenger();
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		bool checkValidationLayerSupport();
		std::vector<const char*> getRequiredExtensions();
		void createSwapChain();

		void pickPhysicalDevice();
		bool Device::isDeviceSuitable(VkPhysicalDevice device);

		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		void createLogicalDevice();

		void createSurface();
		
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapChainImages;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
	};
}