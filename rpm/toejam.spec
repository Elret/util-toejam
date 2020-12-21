Name:           toejam
Version:        0.8.4
Release:        1%{?dist}
Summary:        Toejam C++ file project setup application.

License:        GPLv2
Source0:	https://github.com/Elret/util-toejam/archive/toejam-0.8.4.tar.xz


BuildRequires:  g++
BuildRequires:  make


%description
Toejam creates c++ project files, sets up project directories, and creates a make file.

%global debug_package %{nil}

%prep
%setup -q

%build
make %{?_smp_mflags}

%install
%make_install

%files
%{_bindir}/%{name}

%changelog
* Thu 12 17 2020 Elret <dev@noun37.net> - 0.8.4
- Fixed makefile cleaning bin directory without rebuild
- Added CFLAG option to build.
