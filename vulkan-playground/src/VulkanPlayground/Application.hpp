#pragma once

#include "VulkanPlayground/Core.hpp"
#include "VulkanPlayground/Events/Event.hpp"
#include "VulkanPlayground/Events/ApplicationEvent.hpp"

#include "Window.hpp"

namespace VulkanPG {

	class VPL_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};



	// to be deffined in a client
	Application* CreateApplication();

}