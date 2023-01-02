#pragma once

#include "VulkanPlayground/Core.hpp"
#include "VulkanPlayground/Events/Event.hpp"
#include "VulkanPlayground/Events/ApplicationEvent.hpp"

#include "Window.hpp"
#include "Core/Device.hpp"

namespace VulkanPG {

	class VPL_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		static Application& Get() { return *s_Instance; }

		Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		Device device;
		static Application* s_Instance;
	};

	// to be deffined in a client
	Application* CreateApplication();
}