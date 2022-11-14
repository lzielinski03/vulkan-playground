#include "Application.hpp"

#include "VulkanPlayground/Events/ApplicationEvent.hpp"
#include "VulkanPlayground/Log.hpp"

namespace VulkanPG {
	Application::Application()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			VPL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			VPL_TRACE(e);
		}
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (true);
	}
	
}