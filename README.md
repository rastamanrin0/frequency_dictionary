# frequency_dictionary
docker build -t frequency_dictionary .
docker run --rm -v $(pwd)/data:/app/data frequency_dictionary /app/data/input.txt /app/data/output.txt