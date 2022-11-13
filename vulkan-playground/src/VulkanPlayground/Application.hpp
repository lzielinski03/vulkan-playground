#pragma once

#include "Core.hpp"

namespace VulkanPG {

	class VPL_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be deffined in a client
	Application* CreateApplication();

}