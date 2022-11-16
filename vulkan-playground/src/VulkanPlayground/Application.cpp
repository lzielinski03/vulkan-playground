#include "pch.hpp"
#include "VulkanPlayground/Application.hpp"

#include "VulkanPlayground/Events/ApplicationEvent.hpp"
#include "VulkanPlayground/Log.hpp"
#include "GLFW/glfw3.h"

namespace VulkanPG {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
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
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
	
}