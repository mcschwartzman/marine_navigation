from setuptools import setup

package_name = 'sensor_fusion_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mcschwartzman',
    maintainer_email='mcschwartzman@outlook.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': ['pytest']
    },
    entry_points={
        'console_scripts': [
            'fused_data = sensor_fusion_pkg.fused_data:main'
        ],
    },
)
