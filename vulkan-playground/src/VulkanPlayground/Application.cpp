#include "pch.hpp"
#include "VulkanPlayground/Application.hpp"
//#include "VulkanPlayground/Log.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace VulkanPG {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		
		if (glfwVulkanSupported())
		{
			VPL_CORE_TRACE("Vulkan is available, at least for compute");
			uint32_t extensionCount = 0;

			vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
			std::vector<VkExtensionProperties> extensions(extensionCount);

			vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
			
			VPL_CORE_TRACE("{0} extensions supported\n", extensionCount);
			for (const auto& extension : extensions) {
				//std::cout << '\t' << extension.extensionName << '\n';
				VPL_CORE_TRACE("\t{0}", extension.extensionName);
			}
			VkApplicationInfo appInfo{};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pApplicationName = "Hello Triangle";
			appInfo.applicationVersion = VK_MAKE_API_VERSION(1, 0, 0, 0);
			appInfo.pEngineName = "No Engine";
			appInfo.engineVersion = VK_MAKE_API_VERSION(1, 0, 0, 0);
			appInfo.apiVersion = VK_API_VERSION_1_0;

			VkInstanceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			createInfo.pApplicationInfo = &appInfo;

			uint32_t glfwExtensionCount = 0;
			const char** glfwExtensions;

			glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

			createInfo.enabledExtensionCount = glfwExtensionCount;
			createInfo.ppEnabledExtensionNames = glfwExtensions;
			//VPL_CORE_TRACE("glfwExtensionCount {0}", glfwExtensionCount);
			//VPL_CORE_TRACE("glfwExtensions {0}", glfwExtensions);

			createInfo.enabledLayerCount = 0;

			if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
				throw std::runtime_error("failed to create instance!");
			}
		}
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		VPL_CORE_TRACE("{0}", e);

	}

	void Application::Run()
	{
		/*
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			VPL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			VPL_TRACE(e);
		}*/

		while (m_Running)
		{
			//glClearColor(1, 0, 1, 1);
			//glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}