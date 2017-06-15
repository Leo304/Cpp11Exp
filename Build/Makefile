ifeq ($(OS), )
$(error Need to set OS!)
endif

L_STAGE = $(STAGE)
ifneq ($(L_STAGE), release)
ifneq ($(L_STAGE), debug)
L_STAGE = release
endif
endif 

ifeq ($(OS), rs6000aix) 

VACPP_PATH=/opt/IBM/xlC/13.1.3/bin
CXX = $(VACPP_PATH)/xlC_r -qrtti

ifeq ($(L_STAGE), debug)
CXXFLAGS   += -g -D_DEBUG
endif

ifeq ($(L_STAGE), release)
CXXFLAGS   += -O2
endif

MY_DEFINES = $(CXXFLAGS) \
	-qlanglvl=nullptr \
	-qlanglvl=extc1x \
	-qlanglvl=rvaluereferences \
	-D__IBMCPP_TR1__
	

MY_INCLUDES = \
	-I../Source/Menu \
	-I../Source/References \
	-I../Source/Container \
	-I../Source/APDFL \
	-I../Source/Math \
	-I../Source/XML

OS_VER := $(strip aix$(shell uname -v).$(shell uname -r))
#OS_VER := $(OS_VER).$(shell uname -r)

OBJDIR = $(OS)/$(L_STAGE)/aix7.1

ALLOBJFILES = $(MENU_OBJS) $(REF_OBJS) $(CONT_OBJS)

EXE_FULL_NAME = $(OBJDIR)/Cpp11Exp

all : create_dirs $(EXE_FULL_NAME)
	
MENU_CPP_OBJS = \
	$(OBJDIR)/Cpp11Exp.o\
	$(OBJDIR)/Item.o\
	$(OBJDIR)/Menu.o 

MENU_OBJS = $(MENU_CPP_OBJS)

MENU_SRC_DIR = ../Source/Menu

MENU_CPP = $(CXX) $(MY_DEFINES) $(MY_INCLUDES) -I$(MENU_SRC_DIR) -c $< -o $@
	
$(MENU_CPP_OBJS) : $(OBJDIR)/%.o : $(MENU_SRC_DIR)/%.cpp
	@echo Compiling $<
	$(MENU_CPP)

REF_CPP_OBJS = \
	$(OBJDIR)/ReferenceItem.o

REF_OBJS = $(REF_CPP_OBJS)	

REF_SRC_DIR = ../Source/References

REF_CPP = $(CXX) $(MY_DEFINES) $(MY_INCLUDES) -I$(REF_SRC_DIR) -c $< -o $@

$(REF_CPP_OBJS) : $(OBJDIR)/%.o : $(REF_SRC_DIR)/%.cpp
	@echo Compiling $<
	$(REF_CPP)
	
CONT_CPP_OBJS = \
	$(OBJDIR)/ArrayItem.o

CONT_OBJS = $(CONT_CPP_OBJS)	

CONT_SRC_DIR = ../Source/Container

CONT_CPP = $(CXX) $(MY_DEFINES) $(MY_INCLUDES) -I$(CONT_SRC_DIR) -c $< -o $@

$(CONT_CPP_OBJS) : $(OBJDIR)/%.o : $(CONT_SRC_DIR)/%.cpp
	@echo Compiling $<
	$(CONT_CPP)
	
APDFL_CPP_OBJS = \
	$(OBJDIR)/APDFLItem.o

APDFL_OBJS = $(APDFL_CPP_OBJS)	

APDFL_SRC_DIR = ../Source/APDFL

APDFL_CPP = $(CXX) $(MY_DEFINES) $(MY_INCLUDES) -I$(APDFL_SRC_DIR) -c $< -o $@

$(APDFL_CPP_OBJS) : $(OBJDIR)/%.o : $(APDFL_SRC_DIR)/%.cpp
	@echo Compiling $<
	$(APDFL_CPP)

MATH_CPP_OBJS = \
	$(OBJDIR)/Fraction.o \
	$(OBJDIR)/FractionItem.o \
	$(OBJDIR)/LRoundItem.o

MATH_OBJS = $(MATH_CPP_OBJS)	

MATH_SRC_DIR = ../Source/Math

MATH_CPP = $(CXX) $(MY_DEFINES) $(MY_INCLUDES) -I$(MATH_SRC_DIR) -c $< -o $@

$(MATH_CPP_OBJS) : $(OBJDIR)/%.o : $(MATH_SRC_DIR)/%.cpp
	@echo Compiling $<
	$(MATH_CPP)

XML_CPP_OBJS = \
	$(OBJDIR)/SF39732Xml.o \
	$(OBJDIR)/XMLItem.o \
	$(OBJDIR)/SimpleXML.o

XML_OBJS = $(XML_CPP_OBJS)	

XML_SRC_DIR = ../Source/XML

XML_CPP = $(CXX) $(MY_DEFINES) $(MY_INCLUDES) -I$(XML_SRC_DIR) -c $< -o $@

$(XML_CPP_OBJS) : $(OBJDIR)/%.o : $(XML_SRC_DIR)/%.cpp
	@echo Compiling $<
	$(XML_CPP)

$(EXE_FULL_NAME) : $(ALLOBJFILES)
	@echo ALLOBJFILES=$(ALLOBJFILES)  
	$(CXX) -o $(EXE_FULL_NAME) -qipa $(ALLOBJFILES)
	
display:
	@echo ALLOBJFILES=$(ALLOBJFILES)
	
else
$(error At this time the OS $(OS)is not supported!)
endif

.PHONY: create_dirs

create_dirs :
	@-mkdir -p ${OBJDIR}
