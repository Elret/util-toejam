Name:           toejam
Version:        0.8.3
Release:        1%{?dist}
Summary:        Toejam C++ file project setup application.

License:        GPLv2
Source0:	https://github.com/Elret/util-toejam/archive/toejam-0.8.3.tar.xz


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
* Tue Oct 20 2020 Elret <dev@noun37.net> - 0.8.0
- Test build of Toejam package.
- Fixed no-arguments bug and cleaned up code.
- Added recursive directory scanning.
