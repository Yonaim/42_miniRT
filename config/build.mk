# dependency rule
ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEPS)
endif
