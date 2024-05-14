from importlib.abc import MetaPathFinder
from importlib.abc import Loader
from importlib.util import spec_from_loader
from importlib.machinery import ModuleSpec


class PackageLoader(Loader):
    def create_module(self, spec):
        pass

    def exec_module(self, module):
        pass


def create_package_spec(name):
    return ModuleSpec(name, PackageLoader(), origin="fake package", is_package=True)


class PackageFinder(MetaPathFinder):
    def __init__(self, packages):
        self.packages = set(packages)

    def find_spec(self, fullname, path, target=None):
        if fullname in self.packages:
            return create_package_spec(fullname)
        return None
