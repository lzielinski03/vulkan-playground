#include "pch.hpp"
#include "VulkanPlayground/Application.hpp"
//#include "VulkanPlayground/Log.hpp"

namespace VulkanPG {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		VPL_CORE_TRACE("Application constructor");
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		//createInstance();
		//instance = Device();
		device.initVulkan(*m_Window);
		
		VPL_CORE_TRACE("Device initVulkan window Height: {0}", m_Window.get()->GetHeight());

	}

	Application::~Application()
	{
		//vkDestroyInstance(instance, nullptr);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		//VPL_CORE_TRACE("{0}", e);
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