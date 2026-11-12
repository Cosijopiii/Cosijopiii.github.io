---
layout: page
permalink: /projects/
title: Projects
description: Research projects and the papers behind them
nav: true
nav_order: 3
---

<div class="research-projects">
  {% assign research_projects = site.projects | where: "category", "research" | sort: "importance" %}
  {% for project in research_projects %}
  <article class="card research-project-card">
    {% if project.img %}
    {% include figure.html path=project.img alt=project.title %}
    {% endif %}
    <div class="card-body">
      {% if project.status %}<p class="project-status">{{ project.status }}</p>{% endif %}
      <h2><a href="{{ project.url | relative_url }}">{{ project.title }}</a></h2>
      <p>{{ project.description }}</p>
      <a href="{{ project.url | relative_url }}">Read about the project</a>
      {% if project.github %}
      <span aria-hidden="true"> &middot; </span>
      <a href="{{ project.github }}"><i class="fab fa-github" aria-hidden="true"></i> GitHub</a>
      {% endif %}
    </div>
  </article>
  {% endfor %}
</div>
