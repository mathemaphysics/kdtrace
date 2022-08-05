from skbuild import setup


setup(
    name='kdtrace',
    version='0.0.1',
    author='Your Name',
    author_email='your@email.com',
    description='Add description here',
    long_description='',
    classifiers=[
        "Programming Language :: Python :: 3",
        "Operating System :: OS Independent",
        "License :: OSI Approved :: GNU General Public License v3 (GPLv3)",
    ],
    zip_safe=False,
    packages=["kdtrace"],
    cmake_args=[
        "-DBUILD_TESTING=OFF",
        "-DBUILD_DOCS=OFF",
    ],
    package_dir={"": "python"},
    cmake_install_dir="python/kdtrace",
)
