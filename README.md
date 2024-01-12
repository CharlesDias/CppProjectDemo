# CPP Project Demo

## Building project

1. Access the project folder **CppProjectDemo**

```console
cd CppProjectDemo
```

2. Pull the latest docker image used to build the project.

```console
docker pull charlesdias/cpp_project_demo
```

3. Run the image docker.

```console
docker run --rm -it -v ~/.gitconfig:/etc/gitconfig -v $(pwd):/home/embedded/project charlesdias/cpp_project_demo:latest
```

4. Run the command below inside the Docker container to build the project.

```console
make clean && make build
```

5. Run the application and check the result on data_out.txt file.

```console
make run
```
